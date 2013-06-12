#!/bin/sh
#
# gmetasnapshot - Ganglia gmetad snapshot manager
#
# $FreeBSD: head/sysutils/ganglia-monitor-core/files/gmetasnap.sh 300897 2012-07-14 14:29:18Z beat $

command=`basename $0`

def_rrddir=/var/db/ganglia/rrds
def_snapdir=/var/db/ganglia/snaps
def_snapname=snap
def_comp=gzip

rrddir=$def_rrddir
snapdir=$def_snapdir
snapname=$def_snapname
comp=$def_comp
delete_old=0
quiet=0

usage()
{
	exitcode=$1
	shift
	if [ -n "$*" ]; then
		warn $*
	fi
	cat <<EOU
usage:
	${command} [<options>] save [<snapname>]
	${command} [<options>] restore [<snapname>]

options:
	-D		Delete .old file after creating snapshot.
	-h		Display this message
	-q		Avoid output unless there is an error.
	-r <rrddir>	Set the rrddir [default: ${def_rrddir}]
	-s <snapdir>	Set the snapdir [default: ${def_snapdir}]
	-z <comptype>	Set the compression type.  Valid values are
			gzip, bzip2, and none. [default: ${def_comp}]

notes:
	- The default snapname is: ${def_snapname}
	- ${command} will not create rrddir or snapdir.
EOU
	exit $1
}

err()
{
	exitcode=$1
	shift
	echo ${command} $* >&2
	exit $exitcode
}

warn()
{
	echo ${command} $* >&2
}

status()
{
	if [ $quiet -eq 0 ]; then
		echo $*
	fi
}

compsuffix()
{
	case "$1" in
	gzip)
		echo ".gz"
		;;
	bzip2)
		echo ".bz2"
		;;
	none)
		echo ""
		;;
	*)
		echo "Unsupposed compression type ignored: $1" >&2
		echo ""
		;;
	esac
}

compflag()
{
	case "$1" in
	gzip)
		echo "z"
		;;
	bzip2)
		echo "y"
		;;
	none)
		echo ""
		;;
	*)
		echo "Unsupposed compression type ignored: $1" >&2
		echo ""
		;;
	esac
}

while [ -n "$1" ]; do
	case "$1" in
	-D)
		shift
		delete_old=1
		;;
	-h)
		shift
		usage 0
		;;
	-q)
		shift
		quiet=1
		;;
	-r)
		shift
		if [ -z "$1" ]; then
			usage 1 "-r requires an argument"
		fi
		rrddir=$1
		shift
		;;
	-s)
		shift
		if [ -z "$1" ]; then
			usage 1 "-s requires an argument"
		fi
		snapdir=$1
		shift
		;;
	-z)
		shift
		if [ -z "$1" ]; then
			usage 1 "-z requires an argument"
		fi
		rrddir=$1
		shift
		;;
	-*)
		usage 1 "unknown argument $1"
		;;
	*)
		break
	esac
done

if [ -n "$2" ]; then
	snapname=$2
fi

basefile=${snapdir}/${snapname}.tar`compsuffix ${comp}`
tarcmd="tar `compflag ${comp}`"

case "$1" in
save)
	if [ ! -d ${rrddir} ]; then
		err 2 "rrddir ${rrddir} does not exist"
	fi
	if [ ! -d ${snapdir} ]; then
		err 2 "snapdir ${snapdir} does not exist"
	fi
	status "saving ${rrddir} to ${basefile}"
	cd ${rrddir}
	if ! ${tarcmd}cf ${basefile}.new .; then
		err 2 "Failed to create ${basefile}.new"
	fi
	if [ -e ${basefile} ]; then
		mv ${basefile} ${basefile}.old
		sync
	fi
	mv ${basefile}.new ${basefile}
	sync
	if [ $delete_old -ne 0 ]; then
		rm ${basefile}.old
	fi
	sync
	;;
restore)
	for file in ${basefile} ${basefile}.new ${basefile}.old; do
		if [ -e ${file} ]; then
			if ${tarcmd}tf ${file} >/dev/null 2>&1 ; then
				sourcefile=${file}
				break
			else
				warn "${file} exists but is not a valid tarball.  Ignoring."
			fi
		fi
	done
	if [ -z "$sourcefile" ]; then
		err 1 "no snapshot found in ${snapdir}."
	fi
	status "restoring ${rrddir} from ${sourcefile}"
	if [ ! -d "${rrddir}" ]; then
		err 1 "${rrddir} does not exist"
	fi
	cd ${rrddir}
	${tarcmd}xpf ${sourcefile}
	;;
*)
	usage 1 "unknown command: $1"
	;;
esac
