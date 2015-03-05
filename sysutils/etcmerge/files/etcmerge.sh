#!/bin/sh
# ex:ts=8
# vim:sts=4:sw=4:tw=120
#
# etcmerge - a program to merge an old and a new copy of the FreeBSD /etc
# directory
#

#
# Exit on encountering an error or unknown variable
#
set -e -u

usage() {
    echo "Usage:" 1>&2
    echo "  etcmerge [-d <workdir>] [-e <etcdir>] [-r <refdir>] [-s <srcdir>] \\" 1>&2
    echo "               [init|install]" 1>&2
    echo 1>&2
    echo "    -d   Set work directory for merge.  Defaults to" 1>&2
    echo "               ${HOME}/etc-work/$(date +%Y%m%d%H%M)" 1>&2
    echo "    -e   Set etc directory to merge.  Defaults to /etc" 1>&2
    echo "    -r   Reference copy of etc.  Defaults to /var/db/etc" 1>&2
    echo "    -s   FreeBSD source directory.  Defaults to /usr/src" 1>&2
    echo 1>&2
    echo "  init:      Do full generation of a new etc directory, including merge from the" 1>&2
    echo "             active etc." 1>&2
    echo 1>&2
    echo "  install:   Make the merged etc active, and the newly generated from source etc" 1>&2
    echo "             the new reference.  This prepares for a new merge." 1>&2
    echo 1>&2
    echo 1>&2
    echo "  IMPORTANT: Before running 'install', you should resolve any conflicts" 1>&2
    echo "             reported." 1>&2
    echo "             Any '.diff' files that are left in merged-* directories represent" 1>&2
    echo "             changes that are LOST in the newly merged etc.  These should either" 1>&2
    echo "             be hand-applied or deemed OK to loose." 1>&2
}

#
# Where we store our work files
#
WORKDIR=${HOME}/etc-work/$(date +%Y%m%d%H%M)

while getopts ":d:e:r:s:" ARGUMENT ; do
    case "${ARGUMENT}" in
	d) WORKDIR="${OPTARG}" ;;
	e) ACTIVEETC="${OPTARG}" ;;
	r) REFETC="${OPTARG}" ;;
	s) USRSRC="${OPTARG}" ;;
	*) usage; exit 1 ;;
    esac
done
shift $(($OPTIND - 1))


#
# Where we store class files
#
CLASSDIR=${WORKDIR}/classes

#
# Where the new "root" is linked from
#
NEWROOT="${WORKDIR}/new-base"

#
# Where the new etc is fetched from
#
NEWETC="${WORKDIR}/etc-new"

#
# Where we store our backup copy of an unmodified etc
#
REFETC=/var/db/etc

#
# Where the active copy of etc is stored
#
ACTIVEETC=/etc

#
# Where does our main merged tree go?
#
MERGEDETC=${WORKDIR}/etc-merged

#
# Where is our source code?
#
USRSRC=/usr/src

#
# How do we use CPIO for extract?
#
CPIO_EXTRACT="cpio -i -d -u --quiet"

#
# How do we use CPIO for archiving?
#
CPIO_ARCHIVE="cpio -o -H crc --quiet"

#
# Show number of conflicts for a particular class
#
conflictshow() {
    id=$1
    if [ -s "${WORKDIR}/${id}.conflicts" ]; then
	echo "ETCMERGE: >>>>"
	echo "ETCMERGE: >>>> Class ${id}: $(cat "${WORKDIR}/${id}.conflicts" | wc -l) conflict(s)"
    fi
}

if [ "$#" -lt 1 ]; then
    usage
    exit 1
fi
case "$1" in
    init)    ;;
    install)
	if ! [ -d "etc-merged" -a "etc-new" ]; then
	    echo "install attempted without standing in work directory" 1>&2
	    echo "cd to work directory (by default under ${HOME}/etc-work/) and try again." 1>&2
	    exit 1
	fi
	for i in $(cat *.conflicts 2> /dev/null); do
	    if egrep -q '^(<<<<<<< |=======$|>>>>>>> )' etc-merged/$i; then
		echo "Unresolved conflicts in ${i}" 1>&2
		exit 1
	    fi
	done
	# XXX Check for need?
	/usr/sbin/pwd_mkdb -d etc-merged -p etc-merged/master.passwd
	/usr/bin/cap_mkdb etc-merged/login.conf
	if diff -q /etc/mail/aliases etc-merged/mail/aliases > /dev/null; then
	    NEED_NEWALIASES=yes
	else
	    NEED_NEWALIASES=no
	fi
	tmpetc=/etc.$(date +%Y%m%d)
	# XXX The entire set of operations below should be transactional.
	#     This could be achieved by doing the updates as a series of
	#     ln operations, then syncing, then removing the extra files,
	#     and ending with removing the temporary directories, at each
	#     phase recording what phase we are in.
	#
	#     Instead, the system now just prays that error does not
	#     happen in the tiny section where it does the actual rename
	#     operations, and syncs around this.  This is probably still
	#     quicker than doing it the safe way.
	#
	# FIXME Should check for existance beforehand
	mv etc-merged ${tmpetc}
	mv etc-new ${REFETC}.etcmerge
	fsync /
	fsync ${REFETC}.etcmerge
	fsync /var/db
	# Should get everything to disk, one would hope.
	sync && sleep 0.5 && sync && sleep 0.5 && sync && sleep 0.5
	mv /etc/ /etc.etcmergeold
	mv ${tmpetc} /etc
	fsync /
	if [ "${NEED_NEWALIASES}" = "yes" ]; then
	    /usr/bin/newaliases
	fi
	mv ${REFETC} ${REFETC}.etcmergeold
	mv ${REFETC}.etcmerge ${REFETC}
	fsync /var/db
	# Do a sync that can keep running after the program exists.
	sync && sync && sync
	echo "Install done - removing copies of old /etc and old reference." 1>&2
	rm -rf /etc.etcmergeold ${REFETC}.etcmergeold
	echo "Done." 1>&2
	exit 0
	;;
    *)
      usage
      exit 1
      ;;
esac


echo "ETCMERGE: >>> Creating new etc data from ${USRSRC}"
# Also creates our base work directory
mkdir -p ${CLASSDIR}
#
# XXX Make sure we have all needed users and groups before this
#
if ! (mkdir -p "${NEWROOT}" && \
	cd ${USRSRC}/etc && \
	make DESTDIR="${NEWROOT}" distrib-dirs && \
	make DESTDIR="${NEWROOT}" distribution && \
	mv ${NEWROOT}/etc ${NEWETC}); then
    echo "Unable to create new etc directory" 1>& 2
    echo "MERGE FAILED" 1>&2
    exit 1
else
    rm -rf ${NEWROOT} 2> /dev/null || (chflags -R noschg ${NEWROOT} && rm -rf ${NEWROOT}) || \
    (echo "Unable to clean out temp root" 1>&2; echo "MERGE FAILED" 1>&2; exit 1)
fi

echo "ETCMERGE: >>> Finding classes of files"
echo "ETCMERGE: >>> Working from"
echo "ETCMERGE: >>>     Active:    ${ACTIVEETC}"
echo "ETCMERGE: >>>     Reference: ${REFETC}"
echo "ETCMERGE: >>>     New:       ${NEWETC}"

#
# Find list of new files and list of old (reference) files
#
cd $WORKDIR
(cd "${NEWETC}"    && find . -type f -print | sort > ${CLASSDIR}/newetc.files)
(cd "${NEWETC}"    && find . -type d -links 2 -print | sort > ${CLASSDIR}/newetc.emptydirs)
(cd "${NEWETC}"    && find . \! \( -type d -or -type f \) -print | sort > ${CLASSDIR}/newetc.others)
(cd "${REFETC}"    && find . -type f -print | sort > ${CLASSDIR}/refetc.files)
(cd "${REFETC}"    && find . -type d -links 2 -print | sort > ${CLASSDIR}/refetc.emptydirs)
(cd "${REFETC}"    && find . \! \( -type d -or -type f \) -print | sort > ${CLASSDIR}/refetc.others)
(cd "${ACTIVEETC}" && find . -type f -print | sort > ${CLASSDIR}/activeetc.files)
(cd "${ACTIVEETC}"    && find . -type d -links 2 -print | sort > ${CLASSDIR}/activeetc.emptydirs)
(cd "${ACTIVEETC}"    && find . \! \( -type d -or -type f \) -print | sort > ${CLASSDIR}/activeetc.others)

#
# Generate lists of differences on a file level, which effectively divides all
# files into classes:
#
# Id	Ref	New	Active		Action
#  0    Absent	Absent	Absent		(Irrelevant case)
#  1	Absent	Absent	Present		Copy file over, with directory if necessary
#  2	Absent	Present	Absent		Copy file over, with directory if necessary	
#  3	Absent	Present	Present		Store NEW file
#					If there are differences:
#						Store diff 
#						Add to conflict list
#  4	Present	Absent	Absent		Ignore file
#  5	Present	Absent	Present		No differences: Ignore files
#					With differences: Store in conflict
#						directory, with separate diff file
#  6	Present Present Absent		Store in conflict directory
#  7	Present Present Present		Do a 3-way merge, with directory if
#  						necessary.
cd ${CLASSDIR}
for extension in files emptydirs others; do
    cat refetc.${extension} newetc.${extension} activeetc.${extension} | sort -u > alletc.${extension}
    cat refetc.${extension} newetc.${extension} | sort | uniq -d | cat - activeetc.${extension} | sort | uniq -d > ${CLASSDIR}/7.${extension}
    cat alletc.${extension} refetc.${extension} newetc.${extension}	| sort | uniq -u > ${CLASSDIR}/1.${extension}
    cat alletc.${extension} refetc.${extension} activeetc.${extension}	| sort | uniq -u > ${CLASSDIR}/2.${extension}
    cat alletc.${extension} newetc.${extension} activeetc.${extension}	| sort | uniq -u > ${CLASSDIR}/4.${extension}
    cat newetc.${extension} activeetc.${extension}		| sort | uniq -d | cat - refetc.${extension} refetc.${extension} | sort | uniq -u > ${CLASSDIR}/3.${extension}
    cat refetc.${extension} activeetc.${extension}		| sort | uniq -d | cat - newetc.${extension} newetc.${extension} | sort | uniq -u > ${CLASSDIR}/5.${extension}
    cat refetc.${extension} newetc.${extension}			| sort | uniq -d | cat - activeetc.${extension} activeetc.${extension} | sort | uniq -u > ${CLASSDIR}/6.${extension}
done

for i in 1 2 3 4 5 6 7; do
    echo "ETCMERGE: >>>> Class ${i}: $(cat ${CLASSDIR}/$i.files | wc -l) files, $(cat ${CLASSDIR}/$i.emptydirs | wc -l) empty dirs, $(cat ${CLASSDIR}/$i.others | wc -l) others"
done

#
# Create directory for merged data
#
mkdir ${MERGEDETC}

echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 7 files - present everywhere"
echo "ETCMERGE: >>>> Files are handled as an ascii 3-way merge."
echo "ETCMERGE: >>>> Non-files get copied from the ACTIVE etc dir."

#
# Class 7 - present everywhere.  Create a merged directory tree.
#
cd ${MERGEDETC}
(cd ${ACTIVEETC} && cat ${CLASSDIR}/7.files ${CLASSDIR}/7.emptydirs ${CLASSDIR}/7.others | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
for i in $(cat ${CLASSDIR}/7.files); do
    if ! merge -q $i ${REFETC}/$i ${NEWETC}/$i; then
	echo ${i} >> ${WORKDIR}/7.conflicts
    fi
done
conflictshow 7

#
# Class 1 - only present in active directory.  Copy over.
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 1 - only present in active directory"
echo "ETCMERGE: >>>> Both files and non-files get copied."
echo "ETCMERGE: >>>"
cd ${MERGEDETC}
(cd ${ACTIVEETC} && cat ${CLASSDIR}/1.files ${CLASSDIR}/1.emptydirs ${CLASSDIR}/1.others | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}

#
# Class 2 - only present in new directory.  Copy over.
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 2 - only present in new directory"
echo "ETCMERGE: >>>> Both files and non-files get copied."
echo "ETCMERGE: >>>"
cd ${MERGEDETC}
(cd ${NEWETC} && cat ${CLASSDIR}/2.files ${CLASSDIR}/2.emptydirs ${CLASSDIR}/2.others | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}

#
# Class 3 - present in new and active directory, but not ref.
# Use the active directory permissions, but the new file.
# If the files differ, store filename in 3.conflicts and the active version and a diff in merged-changed.
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>>> Handling class 3 - present in new and active directory only"
echo "ETCMERGE: >>>> Files with differences get a copy of NEW file in both"
echo "ETCMERGE: >>>> etc-merged and merged-changed, with a .diff from the NEW to"
echo "ETCMERGE: >>>> the ACTIVE file in merged-changed."
echo "ETCMERGE: >>>> Non-files are fetched from the ACTIVE directory."
echo "ETCMERGE: >>>"
cd ${MERGEDETC}
(cd ${ACTIVEETC} && cat ${CLASSDIR}/3.files ${CLASSDIR}/3.emptydirs ${CLASSDIR}/3.others | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
(cd ${NEWETC} && cat ${CLASSDIR}/3.files | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
for i in $(cat ${CLASSDIR}/3.files); do
    if ! diff -q ${ACTIVEETC}/$i ${REFETC}/$i > /dev/null; then
	# Files differ
	echo $i >> ${WORKDIR}/3.conflicts
    fi
done
conflictshow 3
#
# Handle differing files (if any)
#
if [ -s ${WORKDIR}/3.conflicts ]; then
    mkdir -p ${WORKDIR}/merged-changed
    cd ${WORKDIR}/merged-changed
    (cd ${ACTIVEETC} && cat ${WORKDIR}/3.conflicts | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
    for i in $(cat ${WORKDIR}/3.conflicts); do
	diff -u ${REFETC}/$i $i > $i.diff
    done
fi

#
# Class 4 - present in ref, removed in new and active
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 4 - present in reference only"
echo "ETCMERGE: >>>> A copy of each file is stored in merged-removed."
echo "ETCMERGE: >>>> Non-files get dropped."
echo "ETCMERGE: >>>"
if [ -s ${CLASSDIR}/4.files ]; then
    mkdir -p ${WORKDIR}/merged-removed
    cd ${WORKDIR}/merged-removed
    (cd ${REFETC} && cat ${CLASSDIR}/4.files | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
fi

#
# Class 5 - present in ref and active, removed in new
#
# For all files where the active is different from the reference, create a copy in merged-removed, with a .diff that
# shows what the differences are.
# For all unchanged files, just copy them over.
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 5 - present in reference and active only"
echo "ETCMERGE: >>>> A copy of each ACTIVE file is stored in merged-removed."
echo "ETCMERGE: >>>> If there is a difference between the ACTIVE and the"
echo "ETCMERGE: >>>> REFERENCE file, a diff from REFERENCE to ACTIVE gets"
echo "ETCMERGE: >>>> stored in merged-removed/"
echo "ETCMERGE: >>>> Non-files get dropped."
echo "ETCMERGE: >>>"
if [ -s ${CLASSDIR}/5.files ]; then
    mkdir -p ${WORKDIR}/merged-removed
    cd ${WORKDIR}/merged-removed
    (cd ${ACTIVEETC} && cat ${CLASSDIR}/5.files | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
    for i in $(cat ${CLASSDIR}/5.files); do
	if ! diff -q ${ACTIVEETC}/$i ${REFETC}/$i > /dev/null; then
	    # Files differ
	    echo $i >> ${WORKDIR}/5.conflicts
	    diff -u ${REFETC}/$i ${ACTIVEETC}/$i > $i.diff
	fi
    done
fi
conflictshow 5

#
# Class 6 - present in ref and new, but removed in active
# Files are copied from new to merged-conflicts, and if the files differ, the filename is added to 6.conflicts, 
# and a .diff file with the changes that are lost is stored alongside the file.
#
echo "ETCMERGE: >>>"
echo "ETCMERGE: >>> Handling class 6 - present in reference and new only"
echo "ETCMERGE: >>>> A copy of the NEW version of each file is stored in"
echo "ETCMERGE: >>>> merged-conflicts/"
echo "ETCMERGE: >>>> If there are differences the REFERENCE and NEW file,"
echo "ETCMERGE: >>>> a .diff file with these is also stored."
echo "ETCMERGE: >>>> Non-files get dropped."
echo "ETCMERGE: >>>"
if [ -s ${CLASSDIR}/6.files ]; then
    mkdir ${WORKDIR}/merged-conflicts
    cd ${WORKDIR}/merged-conflicts
    (cd ${NEWETC} && cat ${CLASSDIR}/6.files | ${CPIO_ARCHIVE}) | ${CPIO_EXTRACT}
    for i in $(cat ${CLASSDIR}/6.files); do
	if ! diff -q $i ${REFETC}/$i > /dev/null; then
	    # Files differ
	    echo $i >> ${WORKDIR}/6.conflicts
	    diff -u ${REFETC}/$i $i > $i.diff
	fi
    done
fi
conflictshow 6

cat <<EOM

Directories (only present if they would have contents)
    etc-merged	      Replaced etc/ directory, ready for use (potentially after
			conflict resolution)
    etc-new	      New etc, generated from ${USRSRC}, and used to generate
			etc-merged.
    merged-removed    Files that have been removed, along with .diff files if
			the active file was different from the reference file.
    merged-changed    Files that have been replaced by the update, along with
			.diff files saying what changes this has resulted in.
    merged-conflicts  Files that are present in new and reference, but not in
			the active etc.  If these are changed, a .diff is
			also stored here.
    classes	      Internal overview of what files belong to what classes

Work directory: ${WORKDIR}
EOM
