#!/bin/sh

if [ -f ${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "PHP configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 9 \
GD		"GD library support" ON \
zlib		"zlib library support" ON \
MySQL		"MySQL database support" ON \
PostgresSQL	"PostgresSQL database support" OFF \
mSQL		"mSQL database support" OFF \
dBase		"dBase database support" OFF 2> /tmp/checklist.tmp.$$

retval=$?

if [ -s /tmp/checklist.tmp.$$ ]; then
	set `cat /tmp/checklist.tmp.$$`
fi
rm -f /tmp/checklist.tmp.$$

case $retval in
	0)	if [ -z "$*" ]; then
			echo "Nothing selected"
		fi
		;;
	1)	echo "Cancel pressed."
		exit 1
		;;
esac

> ${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"GD\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libgd.a:\${PORTSDIR}/graphics/gd" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-gd" >> ${CURDIR}/Makefile.inc
			;;
		\"zlib\")
			echo "PHP3_CONF_ARGS+=	--with-zlib" >> ${CURDIR}/Makefile.inc
			;;
		\"MySQL\")
			echo "BUILD_DEPENDS+=		mysql:\${PORTSDIR}/databases/mysql" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-mysql=\${PREFIX}" >> ${CURDIR}/Makefile.inc
			;;
		\"PostgresSQL\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/pgsql/bin/psql:\${PORTSDIR}/databases/postgresql" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-pgsql=\${PREFIX}/pgsql" >> ${CURDIR}/Makefile.inc
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=		msql:\${PORTSDIR}/databases/msql" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-msql=\${PREFIX}" >> ${CURDIR}/Makefile.inc
			;;
		\"dBase\")
			echo "PHP3_CONF_ARGS+=	--with-dbase" >> ${CURDIR}/Makefile.inc
			;;
	esac
	shift
done
