#!/bin/sh

if [ -f ${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "PHP configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 9 \
GD		"GD library support" ON \
FreeType	"TrueType font rendering (implies GD)" OFF \
zlib		"zlib library support" ON \
MySQL		"MySQL database support" ON \
PostgreSQL	"PostgreSQL database support" OFF \
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
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=		ttf\\\\.2\\\\.:\${PORTSDIR}/print/freetype" >> ${CURDIR}/Makefile.inc
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "PHP3_CONF_ARGS+=	--with-zlib" >> ${CURDIR}/Makefile.inc
			;;
		\"MySQL\")
			echo "BUILD_DEPENDS+=		mysql:\${PORTSDIR}/databases/mysql321" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-mysql=\${PREFIX}" >> ${CURDIR}/Makefile.inc
			;;
		\"PostgreSQL\")
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
