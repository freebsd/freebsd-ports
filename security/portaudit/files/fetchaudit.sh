#!/bin/sh

#
# $FreeBSD$
#

# defaults
daily_status_portaudit_enable="YES"
portaudit_dir="%%DATABASEDIR%%"

# If there is a global system configuration file, suck it in.
#
if [ -r /etc/defaults/periodic.conf ]
then
    . /etc/defaults/periodic.conf
    source_periodic_confs
fi

. %%DATADIR%%/portaudit.functions

MASTER_SITE_LOCAL="
	${MASTER_SITE_LOCAL}
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	ftp://ftp.tw.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
	"

MASTER_SITE_SUBDIR=eik

DISTNAME=auditfile
EXTRACT_SUFX=.tbz

portaudit_file="${portaudit_dir}/${DISTNAME}${EXTRACT_SUFX}"

# site sort order is not overly smart
LOCATIONS=`echo "${MASTER_SITE_LOCAL}" | awk "
		BEGIN { srand() }
		/^[ \t]*\$/ { next }
		{
			gsub(/[ \t]/, \\"\\")
			gsub(/%SUBDIR%/, \\"${MASTER_SITE_SUBDIR}\\")
			print rand() \\"\t\\" \\$0 \\"${DISTNAME}${EXTRACT_SUFX}\\"
		}
	" | sort -n | cut -f 2`

case "$daily_status_portaudit_enable" in
	""|[Yy][Ee][Ss])
		if [ ! -f "${portaudit_file}" ] || checkexpiry_auditfile 5; then
			echo ""
			echo "Updating audit database."
			cd "${portaudit_dir}"
			fetch -1am ${LOCATIONS}
			if [ ! $? ]; then
				echo "Couldn't fetch database."
				rc=2
			elif [ ! -f "${portaudit_file}" ] ; then
				echo "no database."
				rc=2
			elif checksum_auditfile; then
				echo "database corrupt."
				rc=2
			elif checkexpiry_auditfile 7; then
				echo "database too old."
				rc=2
			else
				echo "done"
				rc=1
			fi
		else
			rc=0
		fi
	;;
	*)
		rc=0
	;;
esac

exit "${rc}"
