# ex:ts=4
# $FreeBSD$

if [ -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc ]; then
	exit
fi

tempfile=`/usr/bin/mktemp -t checklist`

if [ "${BATCH}" ]; then
	if [ "${OPTIONS}" ]; then
		set ${OPTIONS}
	else
		set \"tcpwrap\" \"pcap\" \"zlib\"
	fi
else
	/usr/bin/dialog --title "ntop configuration options" --clear \
		--checklist "\n\
Please select desired options:" -1 -1 16 \
tcpwrap		"TCP Wrapper support" ON \
pcap		"libpcap support" ON \
gdbm		"GNU gdbm support" OFF \
zlib		"zlib support" ON \
gd		"GD 1 support" OFF \
rrd		"rrdtool support" OFF \
locale		"locale (i18n) support" OFF \
xmldump		"XML Dump support" OFF \
2> $tempfile

	retval=$?

	if [ -s $tempfile ]; then
		set `cat $tempfile`
	fi
	rm -f $tempfile

	case $retval in
		0)	if [ -z "$*" ]; then
				echo "Nothing selected"
			fi
			;;
		1)	echo "Cancel pressed."
			exit 1
			;;
	esac
fi

${MKDIR} ${WRKDIRPREFIX}${REALCURDIR}
exec > ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"tcpwrap\")
			echo "CONFIGURE_ARGS+=--with-tcpwrap"
			;;

		\"pcap\")
			echo "CONFIGURE_ARGS+=--with-pcap-root=/usr"
			;;

		\"gdbm\")
			echo "LIB_DEPENDS+=	gdbm.3:\${PORTSDIR}/databases/gdbm"
			echo "CONFIGURE_ARGS+=--with-gdbm-root=\${LOCALBASE}"
			;;

		\"zlib\")
			echo "CONFIGURE_ARGS+=--with-zlib-root=/usr"
			;;

		\"gd\")
			echo "LIB_DEPENDS+=	gd.2:\${PORTSDIR}/graphics/gd"
			echo "LIB_DEPENDS+=	png.5:\${PORTSDIR}/graphics/png"
			echo "CONFIGURE_ARGS+=--with-gd-root=\${LOCALBASE}"
			echo "CONFIGURE_ARGS+=--with-libpng-root=\${LOCALBASE}"
			;;

		\"rrd\")
			echo "LIB_DEPENDS+=	rrd.0:\${PORTSDIR}/net/rrdtool"
			echo "CONFIGURE_ARGS+=--with-rrd-root=\${LOCALBASE}"
			;;

		\"locale\")
			echo "LIB_DEPENDS+=	intl.4:\${PORTSDIR}/devel/gettext"
			echo "CONFIGURE_ARGS+=--with-localedir=\${LOCALBASE}/share/locale"
			echo "CONFIGURE_ARGS+=--enable-i18n"
			;;

		\"xmldump\")
			echo "USE_GNOME=	glib12"
			echo "GLIB_PREFIX?=	`\${LOCALBASE}/bin/glib-config --prefix`"
			echo "XML2_PREFIX?=	`\${LOCALBASE}/bin/xml2-config --prefix`"
			echo "LIB_DEPENDS+=	xml2.5:\${PORTSDIR}/textproc/libxml2"
			echo "LIB_DEPENDS+=	gdome.7:\${PORTSDIR}/textproc/gdome2"
			echo "CONFIGURE_ARGS+=--enable-xmldump"
			echo "CONFIGURE_ARGS+=--with-xml2-lib=\${XML2_PREFIX}/lib"
			echo "CONFIGURE_ARGS+=--with-xml2-include=\${XML2_PREFIX}/include/libxml2/libxml"
			echo "CONFIGURE_ARGS+=--with-gdome-lib=\${LOCALBASE}/lib"
			echo "CONFIGURE_ARGS+=--with-gdome-include=\${LOCALBASE}/include/libgdome"
			echo "CONFIGURE_ARGS+=--with-glib-lib=\${GLIB_PREFIX}/lib"
			echo "CONFIGURE_ARGS+=--with-glib-include=\${GLIB_PREFIX}/include/glib12"
			;;

		*)
			echo "Invalid option(s): $*" > /dev/stderr
			rm -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc
			exit 1
			;;
	esac
	shift
done
