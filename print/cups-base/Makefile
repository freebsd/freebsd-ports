# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	1.7.1
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
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
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DSOFLAGS=	-Wl,-rpath,${PREFIX}/lib -L${PREFIX}/lib ${LDFLAGS}
CONFIGURE_ENV=	DSOFLAGS="${DSOFLAGS}"
CONFIGURE_ARGS+=	--localstatedir=/var			\
			--disable-slp				\
			--disable-gssapi			\
			--with-cups-user=${USERS}		\
			--with-cups-group=${GROUPS}		\
			--with-system-groups=${CUPSSYSGRP}	\
			--with-docdir=${DOCSDIR}		\
			--with-icondir=${PREFIX}/share/icons	\
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
PORTREVISION=	0
LICENSE=	LGPL21
CUPS_SUFFIX=	-client
OPTIONS_DEFINE=	GNUTLS
.elif defined(CUPS_IMAGE)
PORTREVISION=	0
CUPS_SUFFIX=	-image
LICENSE=	LGPL21
OPTIONS_DEFINE=	GNUTLS
.else
INSTALLS_ICONS=	yes
PORTREVISION=	0
CUPS_SUFFIX=	-base
OPTIONS_DEFINE=	GNUTLS LIBPAPER PHP PYTHON PAM DBUS LIBUSB XDG_OPEN AVAHI MDNSRESPONDER
OPTIONS_DEFAULT=	LIBPAPER
NO_OPTIONS_SORT=	yes
.endif

LIBUSB_DESC=		USB support
XDG_OPEN_DESC=		Build with XDG_OPEN as browser

.include <bsd.port.options.mk>

.if defined(CUPS_CLIENT)
COMMENT2=	Library cups
INSTALL_WRKSRC=	${WRKSRC}/cups
PLIST=		${MASTERDIR}/pkg-plist.client
USES+=		iconv
LDFLAGS+=	${ICONV_LIB}
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
.if ${ARCH} == "ia64"
BROKEN=		stack-protector not supported on ia64
.endif
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
.else
CONFIGURE_ARGS+=	--disable-gnutls --enable-openssl
WITH_OPENSSL_HACK7=	yes
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=	--with-php
USE_PHP=		yes
USE_PHP_BUILD=		yes
PLIST_SUB+=		PHP=""
.else
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=		PHP="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLIBPAPER}
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		libpaper.so:${PORTSDIR}/print/libpaper
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MMDNSRESPONDER}
.if ${PORT_OPTIONS:MAVAHI}
IGNORE=			You must select one and only one option to build for Zeroconf
.endif
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/mDNSResponder
CONFIGURE_ARGS+=	--with-dnssd-includes=${LOCALBASE}/include
PLIST_SUB+=		WITH_MDNSRESPONDER=""
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-dnssd \
			--with-dnssd-libs=${LOCALBASE}/lib/
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/avahi-libdns
CONFIGURE_ARGS+=	--with-dnssd-includes=${LOCALBASE}/include/avahi-compat-libdns_sd/
BROKEN=			missing function, see http://www.avahi.org/ticket/303
.else
CONFIGURE_ARGS+=	--disable-dnssd
PLIST_SUB+=		WITH_MDNSRESPONDER="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam
PLIST_SUB+=		WITH_PAMD=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		WITH_PAMD="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus-1.so:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
PLIST_SUB+=		WITH_DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus
PLIST_SUB+=		WITH_DBUS="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MXDG_OPEN}
RUN_DEPENDS+=		xdg-open:${PORTSDIR}/devel/xdg-utils
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLIBUSB}
CPPFLAGS+=		-I/usr/include
LDFLAGS+=		-L/usr/lib
CONFIGURE_ARGS+=	--enable-libusb
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif
CONFIGURE_ARGS+=	LIBS="-lssp_nonshared"

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
.if ! ${PORT_OPTIONS:MLIBUSB}
	@${REINPLACE_CMD} -e 's|xyes -o $$uname != Darwin||' ${WRKSRC}/configure
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
	${INSTALL_DATA} ${WRKSRC}/cups/raster.h ${STAGEDIR}${PREFIX}/include/cups
.else
.if  ${PORT_OPTIONS:MGHOSTSCRIPT} || ${PORT_OPTIONS:MXPDF}
	${INSTALL_PROGRAM} ${WRKSRC}/filter/pdftops  ${STAGEDIR}${PREFIX}/libexec/cups/filter/
.endif
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
