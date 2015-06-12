# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	2.0.3
DISTVERSIONSUFFIX=	-source
#PORTREVISION=	defined further
CATEGORIES=	print
MASTER_SITES=	http://www.cups.org/software/${DISTVERSION}/ \
		EASYSW/${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=	${CUPS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common UNIX Printing System: ${COMMENT2}

LICENSE=	GPLv2

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS=	LPRng-[0-9]*

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

USES+=		cpe gmake iconv pkgconfig tar:bzip2
CPE_VENDOR=	apple
DESTDIRNAME=	DSTROOT
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DSOFLAGS=	-Wl,-rpath,${PREFIX}/lib ${LDFLAGS} ${LIBS}
CONFIGURE_ENV=	DSOFLAGS="${DSOFLAGS}"
CONFIGURE_ARGS+=	--localstatedir=/var			\
			--disable-gssapi			\
			--with-cups-user=${USERS}		\
			--with-cups-group=${GROUPS}		\
			--with-system-groups=${CUPSSYSGRP}	\
			--with-docdir=${DOCSDIR}		\
			--with-menudir=${DESKTOPDIR}		\
			--with-domainsocket=${CUPS_SOCKET}	\
			--with-cachedir=${CUPS_CACHEDIR}	\
			--with-pam-module="unix"		\
			--enable-gnutls

CUPS_CACHEDIR?=	/var/db/cups
CUPS_SPOOLDIR=	/var/spool/cups
CUPS_SOCKET?=	/var/run/cups.sock
CUPS_PDFTOPS?=	${LOCALBASE}/libexec/xpdf/pdftops
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CUPSSYSGRP=	wheel
# GROUPS/USERS does not work here
GROUPS=	cups
USERS=		cups

# UNIQUENAME must be set before bsd.port.pre.mk so OPTIONSFILE can be included
OPTIONS_SUB=		yes
.if defined(CUPS_CLIENT)
PORTREVISION=	2
LICENSE=	LGPL21
CUPS_SUFFIX=	-client
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER
OPTIONS_DEFAULT+=	MDNSRESPONDER
.elif defined(CUPS_IMAGE)
PORTREVISION=	2
CUPS_SUFFIX=	-image
LICENSE=	LGPL21
.else
PORTREVISION=	3
CUPS_SUFFIX=	-base
# No DOCS option.  Files are needed by web interface.
OPTIONS_DEFINE=		DBUS ICONS LIBPAPER LIBUSB PAM XDG_OPEN
OPTIONS_GROUP=		WEB
OPTIONS_GROUP_WEB=	JAVA PERL PHP PYTHON
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER
OPTIONS_DEFAULT+=	LIBPAPER MDNSRESPONDER ICONS
.endif

ICONS_DESC=		Desktop icons
LIBUSB_DESC=		USB support
WEB_DESC=		Interpreters for web interfaces
XDG_OPEN_DESC=		Build with XDG_OPEN as browser
ZEROCONF_DESC=		Zeroconf support

.include <bsd.port.options.mk>

.if defined(CUPS_CLIENT)
COMMENT2=	Library cups
INSTALL_WRKSRC=	${WRKSRC}/cups
PLIST=		${MASTERDIR}/pkg-plist.client
LIBS+=		${ICONV_LIB}
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.client
.elif defined(CUPS_IMAGE)
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
# force build if old cups is installed.
BUILD_DEPENDS+=	cups-client${PKGNAMESUFFIX2}>=${PORTVERSION}:${PORTSDIR}/${PKGCATEGORY}/cups-client
COMMENT2=	Library cupsimage
INSTALL_WRKSRC=	${WRKSRC}/filter
PLIST=		${MASTERDIR}/pkg-plist.image
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.image
.else
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		libcupsimage.so:${PORTSDIR}/${PKGCATEGORY}/cups-image
# force build if old cups is installed.
BUILD_DEPENDS+=	cups-client${PKGNAMESUFFIX2}>=${PORTVERSION}:${PORTSDIR}/${PKGCATEGORY}/cups-client
BUILD_DEPENDS+=	cups-image${PKGNAMESUFFIX2}>=${PORTVERSION}:${PORTSDIR}/${PKGCATEGORY}/cups-image
COMMENT2=	Server
USE_RC_SUBR=	cupsd
PLIST_SUB+=	CACHEDIR="${CUPS_CACHEDIR}"
BROKEN_ia64=	stack-protector not supported on ia64
.endif

.if defined(CUPS_OVERWRITE_BASE)
PLIST_SUB+=		OVERWRITE=""
CONFIGURE_ARGS+=	--with-printcap=/etc/printcap
.else
PLIST_SUB+=		OVERWRITE="@comment "
CONFIGURE_ARGS+=	--with-printcap=${PREFIX}/etc/printcap
.endif

# Don't use CONFIGURE_ARGS+=--without-* to disable web interpreters because it
# will set the path of the interpreter to "no" and set it's existence to TRUE.
.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE)
. if ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--with-java=${JAVA}
USE_JAVA=		yes
. endif

. if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--with-perl=${PERL}
USES+=			perl5
. endif

. if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}/bin/php-cgi
USE_PHP=		yes
USE_PHP_BUILD=		yes
WANT_PHP_CGI=		yes
. endif

. if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
USES+=			python
. endif

. if ${PORT_OPTIONS:MLIBPAPER}
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		libpaper.so:${PORTSDIR}/print/libpaper
. endif

. if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam
. else
CONFIGURE_ARGS+=	--disable-pam
. endif

. if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus-1.so:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
. else
CONFIGURE_ARGS+=	--disable-dbus
. endif

. if ${PORT_OPTIONS:MXDG_OPEN}
RUN_DEPENDS+=		xdg-open:${PORTSDIR}/devel/xdg-utils
. endif

. if ${PORT_OPTIONS:MLIBUSB}
CONFIGURE_ARGS+=	--enable-libusb
PLIST_SUB+=		LIBUSB=""
. else
CONFIGURE_ARGS+=	--disable-libusb
PLIST_SUB+=		LIBUSB="@comment "
. endif

. if ${PORT_OPTIONS:MICONS}
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=	--with-icondir=${PREFIX}/share/icons
. endif

SUB_FILES+=	ulpt-cupsd.conf ulpt-cupsd.sh
.endif

.if !defined(CUPS_IMAGE)
. if ${PORT_OPTIONS:MMDNSRESPONDER}
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/mDNSResponder
CONFIGURE_ARGS+=	--enable-dnssd
CONFIGURE_ARGS+=	--with-dnssd-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-avahi
SUB_LIST+=		ZEROCONF="mdnsd"
. elif ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-avahi
CONFIGURE_ARGS+=	--disable-dnssd
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app
SUB_LIST+=		ZEROCONF="avahi_daemon"
. else
CONFIGURE_ARGS+=	--disable-dnssd
CONFIGURE_ARGS+=	--disable-avahi
SUB_LIST+=		ZEROCONF=""
. endif
.endif

.if ${OSVERSION} < 1000036 && ${ARCH} == i386
LIBS+=		-lssp_nonshared
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_search_libiconv_open=no
.endif

post-patch:
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e 's|@PIEFLAGS@||' ${WRKSRC}/Makedefs.in
.endif
.if ${PORT_OPTIONS:MMDNSRESPONDER}
	@${REINPLACE_CMD} -e 's|Darwin|FreeBSD|' \
		${WRKSRC}/backend/Makefile
.endif
.if  ${PORT_OPTIONS:MXDG_OPEN}
	@${REINPLACE_CMD} -e 's|htmlview|xdg-open|' ${WRKSRC}/desktop/cups.desktop.in
.endif
	@${REINPLACE_CMD} -e '/SILENT/d' ${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} -e 's|/etc/cups|${LOCALBASE}/etc/cups|g' ${WRKSRC}/man/*.man*
	@${REINPLACE_CMD} -e 's|/private/etc/pam.d|${LOCALBASE}/etc/pam.d|' \
		-e 's|-D_LARGEFILE64_SOURCE||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|\.default|.sample|'\
		${WRKSRC}/cgi-bin/admin.c\
		${WRKSRC}/CHANGES-1.3.txt\
		${WRKSRC}/conf/Makefile\
		${WRKSRC}/packaging/cups.list.in\
		${WRKSRC}/packaging/cups.spec\
		${WRKSRC}/packaging/cups.spec.in
.if defined(CUPS_CLIENT)
	@${REINPLACE_CMD} \
		-e 's|cups test|cups|' \
		-e 's|cups filter |cups |' \
		-e 's|driver ppdc scheduler||' \
		-e 's|$$.PHPDIR. $$.FONTS.||' \
		${WRKSRC}/Makefile
.elif defined(CUPS_IMAGE)
	@${REINPLACE_CMD} \
		-e 's|cups test||' \
		-e 's|cups filter |filter |' \
		-e 's|driver ppdc scheduler||' \
		-e 's|$$.PHPDIR. $$.FONTS.||' \
		${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} \
		-e 's|cups test|test|' \
		-e 's|cups filter driver|driver|' \
		-e '/cd cups/d' \
		-e 's|$$.INSTALL_SCRIPT. cups-config|echo skip: cups-config|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|cups-config.$$.MAN1EXT. ||' \
		${WRKSRC}/man/Makefile
.endif

post-configure:
.if defined(CUPS_CLIENT)
	@${REINPLACE_CMD} \
		-e 's|filter .* templates||' \
		${WRKSRC}/Makedefs
.elif defined(CUPS_IMAGE)
	@${REINPLACE_CMD} \
		-e 's|filter .* templates|filter|' \
		${WRKSRC}/Makedefs
.else
	@${REINPLACE_CMD} \
		-e 's|filter backend|backend|' \
		-e 's|/etc/pam.d|${LOCALBASE}/etc/pam.d|'\
		${WRKSRC}/Makedefs
.endif

.if !defined(CUPS_CLIENT)
pre-build:
	${CP} -p ${LOCALBASE}/lib/libcups.a ${WRKSRC}/cups/
	${CP} -p ${LOCALBASE}/lib/libcups.so ${WRKSRC}/cups/
	${CP} -p ${LOCALBASE}/lib/libcups.so.2 ${WRKSRC}/cups/
.if !defined(CUPS_IMAGE)
	${CP} -p ${LOCALBASE}/lib/libcupsimage.so ${WRKSRC}/filter/
	${CP} -p ${LOCALBASE}/lib/libcupsimage.so.2 ${WRKSRC}/filter/
.endif
.endif

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/*.so.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/*.so.*
.if defined(CUPS_CLIENT)
	${INSTALL_SCRIPT} ${WRKSRC}/cups-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cups/libcups.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/cups-config.man ${STAGEDIR}${PREFIX}/man/man1/cups-config.1
.elif defined(CUPS_IMAGE)
.else
	${LN} -sf lpr ${STAGEDIR}${PREFIX}/bin/lpr-cups
	${MKDIR} ${STAGEDIR}${ETCDIR}/
.for f in cupsd.conf mime.convs mime.types snmp.conf
	test -f ${STAGEDIR}${ETCDIR}/${f} && ${RM} -f ${STAGEDIR}${ETCDIR}/${f} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/cups-files.conf ${STAGEDIR}${ETCDIR}/cups-files.conf.sample
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/ulpt-cupsd.conf ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/ulpt-cupsd.sh ${STAGEDIR}${PREFIX}/sbin/
.endif

.include <bsd.port.post.mk>
