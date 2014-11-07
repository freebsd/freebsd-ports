# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	1.7.3
DISTVERSIONSUFFIX=	-source
#PORTREVISION=	defined further
CATEGORIES=	print
MASTER_SITES=	http://www.cups.org/software/${DISTVERSION}/ \
		EASYSW/${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=	${CUPS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common UNIX Printing System: ${COMMENT2}

LICENSE=	GPLv2

CONFLICTS=	LPRng-[0-9]*

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

USES+=		gmake pkgconfig tar:bzip2
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
			--enable-ssl

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
.if defined(CUPS_CLIENT)
PORTREVISION=	2
LICENSE=	LGPL21
CUPS_SUFFIX=	-client
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes
.elif defined(CUPS_IMAGE)
PORTREVISION=	1
CUPS_SUFFIX=	-image
LICENSE=	LGPL21
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes
.else
PORTREVISION=	2
CUPS_SUFFIX=	-base
# No DOCS option.  Files are needed by web interface.
OPTIONS_DEFINE=		DBUS ICONS LIBPAPER LIBUSB PAM XDG_OPEN
OPTIONS_GROUP=		WEB
OPTIONS_GROUP_WEB=	JAVA PERL PHP PYTHON
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER
OPTIONS_DEFAULT=	LIBPAPER MDNSRESPONDER OPENSSL ICONS
OPTIONS_SUB=		yes
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
USES+=		iconv
LIBS+=		${ICONV_LIB}
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.client
.elif defined(CUPS_IMAGE)
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
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

.if ${PORT_OPTIONS:MGNUTLS}
CONFIGURE_ARGS+=	--disable-openssl --enable-gnutls
LIB_DEPENDS+=		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
			libgnutls.so:${PORTSDIR}/security/gnutls
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--disable-gnutls --enable-openssl
.endif

# Don't use CONFIGURE_ARGS+=--without-* to disable web interpreters because it
# will set the path of the interpreter to "no" and set it's existence to TRUE.
.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--with-java=${JAVA}
USE_JAVA=		yes
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--with-perl=${PERL}
USES+=			perl5
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}/bin/php-cgi
USE_PHP=		yes
USE_PHP_BUILD=		yes
WANT_PHP_CGI=		yes
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
USES+=			python
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLIBPAPER}
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		libpaper.so:${PORTSDIR}/print/libpaper
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MMDNSRESPONDER}
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/mDNSResponder
CONFIGURE_ARGS+=	--with-dnssd-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-avahi
SUB_LIST+=		ZEROCONF="mdnsd"
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app
SUB_LIST+=		ZEROCONF="avahi_daemon"
.else
CONFIGURE_ARGS+=	--disable-dnssd
CONFIGURE_ARGS+=	--disable-avahi
SUB_LIST+=		ZEROCONF=""
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus-1.so:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MXDG_OPEN}
RUN_DEPENDS+=		xdg-open:${PORTSDIR}/devel/xdg-utils
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLIBUSB}
CONFIGURE_ARGS+=	--enable-libusb
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MICONS}
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=	--with-icondir=${PREFIX}/share/icons
.endif

.if ${OSVERSION} < 1000036 && ${ARCH} == i386
LIBS+=		-lssp_nonshared
.endif

.if ! defined(CUPS_CLIENT) && ! defined(CUPS_IMAGE)
SUB_FILES+=	ulpt-cupsd.conf ulpt-cupsd.sh
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
	@${REINPLACE_CMD} -e 's|-lpthreads.*;|${PTHREAD_LIBS};|g' \
		-e 's|/private/etc/pam.d|${LOCALBASE}/etc/pam.d|' \
		-e 's|-D_LARGEFILE64_SOURCE||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
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
.if defined(CUPS_CLIENT)
	${INSTALL_SCRIPT} ${WRKSRC}/cups-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cups/libcups.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/cups-config.man ${STAGEDIR}${PREFIX}/man/man1/cups-config.1
.elif defined(CUPS_IMAGE)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcupsimage.so.2
.else
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcupscgi.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcupsppdc.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcupsmime.so.1
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

.include <bsd.port.mk>
