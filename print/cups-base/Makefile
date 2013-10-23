# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	1.5.4
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	EASYSW/${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=	${CUPS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common UNIX Printing System: ${COMMENT2}

LICENSE=	GPLv2

CONFLICTS=	LPRng-[0-9]*

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DSOFLAGS=	-Wl,-rpath,${PREFIX}/lib -L${PREFIX}/lib ${LDFLAGS}
CONFIGURE_ENV=	DSOFLAGS="${DSOFLAGS}"
CONFIGURE_ARGS+=	--localstatedir=/var			\
			--disable-slp				\
			--disable-gssapi			\
			--with-cups-user=${CUPSOWN}		\
			--with-cups-group=${CUPSGRP}		\
			--with-system-groups=${CUPSSYSGRP}	\
			--with-docdir=${DOCSDIR}		\
			--with-icondir=${PREFIX}/share/icons	\
			--with-menudir=${DESKTOPDIR}		\
			--with-domainsocket=${CUPS_SOCKET}	\
			--with-cachedir=${CUPS_CACHEDIR}	\
			--with-pam-module="unix"		\
			--enable-ssl

CUPS_ETCDIR=	${PREFIX}/etc/cups
CUPS_CACHEDIR?=	/var/db/cups
CUPS_SPOOLDIR=	/var/spool/cups
CUPS_SOCKET?=	/var/run/cups.sock
CUPS_PDFTOPS?=	${LOCALBASE}/libexec/xpdf/pdftops
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# file, dir ownership
CUPSGRP=	cups
CUPSOWN=	cups
CUPSSYSGRP=	wheel
# GROUPS/USERS does not work here
#GROUPS=	cups
#USERS=		cups

# UNIQUENAME must be set before bsd.port.pre.mk so OPTIONSFILE can be included
.if defined(CUPS_CLIENT)
PORTREVISION=	1
LICENSE=	LGPL21
CUPS_SUFFIX=	-client
OPTIONS_DEFINE=	GNUTLS
.elif defined(CUPS_IMAGE)
PORTREVISION=	1
CUPS_SUFFIX=	-image
LICENSE=	LGPL21
OPTIONS_DEFINE=	GNUTLS
.else
INSTALLS_ICONS=	yes
PORTREVISION=	1
CUPS_SUFFIX=	-base
OPTIONS_DEFINE=	GNUTLS LIBPAPER PHP PYTHON PAM LDAP DBUS LIBUSB XDG_OPEN GHOSTSCRIPT XPDF AVAHI MDNSRESPONDER
OPTIONS_DEFAULT=	LIBPAPER GHOSTSCRIPT
NO_OPTIONS_SORT=	yes
.endif

LIBUSB_DESC=		USB support
GHOSTSCRIPT_DESC=	Build pdftops with GHOSTSCRIPT
XPDF_DESC=		Build pdftops with XPDF
XDG_OPEN_DESC=		Build with XDG_OPEN as browser

NO_STAGE=	yes
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
LIB_DEPENDS+=	cups:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff
# force build if old cups is installed.
BUILD_DEPENDS+=	cups-client${PKGNAMESUFFIX2}>=${PORTVERSION}:${PORTSDIR}/${PKGCATEGORY}/cups-client
COMMENT2=	Library cupsimage
CONFIGURE_ARGS+=	--disable-pdftops
INSTALL_WRKSRC=	${WRKSRC}/filter
PLIST=		${MASTERDIR}/pkg-plist.image
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.image
.else
LIB_DEPENDS+=	cups:${PORTSDIR}/${PKGCATEGORY}/cups-client
LIB_DEPENDS+=	cupsimage:${PORTSDIR}/${PKGCATEGORY}/cups-image
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
LIB_DEPENDS+=		gcrypt:${PORTSDIR}/security/libgcrypt
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
USES+=		pkgconfig
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

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MGHOSTSCRIPT}
.if ${PORT_OPTIONS:MXPDF}
IGNORE=			You must select one and only one option to build pdftops
.endif
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--enable-pdftops --with-pdftops=${LOCALBASE}/bin/gs
PLIST_SUB+=		WITH_PDFTOPS=""
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MXPDF}
BUILD_DEPENDS+=		${CUPS_PDFTOPS}:${PORTSDIR}/graphics/xpdf
RUN_DEPENDS+=		${CUPS_PDFTOPS}:${PORTSDIR}/graphics/xpdf
CONFIGURE_ARGS+=	--enable-pdftops --with-pdftops=${CUPS_PDFTOPS}
PLIST_SUB+=		WITH_PDFTOPS=""
.else
PLIST_SUB+=		WITH_PDFTOPS="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLIBPAPER}
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		paper:${PORTSDIR}/print/libpaper
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MMDNSRESPONDER}
.if ${PORT_OPTIONS:MAVAHI}
IGNORE=			You must select one and only one option to build for Zeroconf
.endif
LIB_DEPENDS+=		dns_sd:${PORTSDIR}/net/mDNSResponder
CONFIGURE_ARGS+=	--with-dnssd-includes=${LOCALBASE}/include
PLIST_SUB+=		WITH_MDNSRESPONDER=""
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-dnssd \
			--with-dnssd-libs=${LOCALBASE}/lib/
LIB_DEPENDS+=		dns_sd:${PORTSDIR}/net/avahi-libdns
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

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		dbus-1:${PORTSDIR}/devel/dbus
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
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif
CONFIGURE_ARGS+=	LIBS="-lssp_nonshared"

.if defined(CUPS_CLIENT)
MAN1=	cups-config.1
.elif defined(CUPS_IMAGE)
.else
MAN1+=	cancel.1 \
	cupstestdsc.1 \
	cupstestppd.1 \
	ipptool.1 \
	lp.1 \
	lpoptions.1 \
	lppasswd.1 \
	lpq.1 \
	lprm.1 \
	lpr.1 \
	lpstat.1 \
	ppdc.1 \
	ppdhtml.1 \
	ppdi.1 \
	ppdmerge.1 \
	ppdpo.1
MAN5=	classes.conf.5 \
	client.conf.5 \
	cups-snmp.conf.5 \
	cupsd.conf.5 \
	ipptoolfile.5 \
	mailto.conf.5 \
	mime.convs.5 \
	mime.types.5 \
	ppdcfile.5 \
	printers.conf.5 \
	subscriptions.conf.5
MAN7=	backend.7 \
	filter.7 \
	notifier.7
MAN8=	accept.8 \
	cupsaccept.8 \
	cupsaddsmb.8 \
	cupsctl.8 \
	cupsd.8 \
	cupsenable.8 \
	cupsfilter.8 \
	cups-deviced.8 \
	cups-driverd.8 \
	cups-lpd.8 \
	cups-polld.8 \
	lpadmin.8 \
	lpinfo.8 \
	lpmove.8 \
	lpc.8

MLINKS=	accept.8 reject.8 \
	cupsaccept.8 cupsreject.8 \
	cupsenable.8 cupsdisable.8

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
		-e 's|$$.INSTALL_SCRIPT. cups-config|echo skip: cups-config|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|cups-config.$$.MAN1EXT. ||' \
		${WRKSRC}/man/Makefile
.endif

pre-configure::
	@${ECHO_MSG} Configuring CUPS with options:
	@${ECHO_MSG} ${CONFIGURE_ARGS} | fmt

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

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE)
post-build:
	cd ${WRKSRC}/filter && ${MAKE} pdftops
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE)
pre-su-install:
	@${INSTALL} -d ${DESKTOPDIR}/
	if ! pw groupshow ${CUPSGRP}; then pw groupadd ${CUPSGRP} -g 193; fi
	if ! pw usershow ${CUPSOWN}; then pw useradd ${CUPSOWN} -g ${CUPSGRP} -u 193 \
		-h - -d ${NONEXISTENT} -s /usr/sbin/nologin -c "CUPS Owner"; fi
.if defined(CUPS_OVERWRITE_BASE)
	if test -e /usr/bin/lp; then ${CHMOD} -h 0 /usr/bin/lp; fi
	if test -e /usr/bin/lpq; then ${CHMOD} -h 0 /usr/bin/lpq; fi
	if test -e /usr/bin/lpr; then ${CHMOD} -h 0 /usr/bin/lpr; fi
	if test -e /usr/bin/lprm; then ${CHMOD} -h 0 /usr/bin/lprm; fi
	if test -e /usr/sbin/lpc; then ${CHMOD} -h 0 /usr/sbin/lpc; fi
.endif
.endif

post-install:
.if defined(CUPS_CLIENT)
	${INSTALL_SCRIPT} ${WRKSRC}/cups-config ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/cups/libcups.a ${PREFIX}/lib/
	${INSTALL_MAN} ${WRKSRC}/man/cups-config.man ${PREFIX}/man/man1/cups-config.1
.elif defined(CUPS_IMAGE)
	${INSTALL_DATA} ${WRKSRC}/cups/raster.h ${PREFIX}/include/cups/
.else
.if  ${PORT_OPTIONS:MGHOSTSCRIPT} || ${PORT_OPTIONS:MXPDF}
	${INSTALL_PROGRAM} ${WRKSRC}/filter/pdftops ${PREFIX}/libexec/cups/filter/
.endif
	${LN} -sf ${PREFIX}/bin/lpr ${PREFIX}/bin/lpr-cups
	${INSTALL} -d ${CUPS_ETCDIR}/
	${CP} -p ${WRKSRC}/conf/snmp.conf ${WRKSRC}/conf/snmp.conf.N
.for f in cupsd.conf mime.convs mime.types snmp.conf
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${CUPS_ETCDIR}/${f}.N
	cd ${CUPS_ETCDIR}/; if test ! -f ${f}; then ${CP} -p ${f}.N ${f}; fi
.endfor
.if  ${PORT_OPTIONS:MPAM}
	@if [ ! -f ${PREFIX}/etc/pam.d/cups ]; then \
		${CP} -p ${PREFIX}/etc/pam.d/cups.default \
		${PREFIX}/etc/pam.d/cups ; \
	fi
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/ulpt-cupsd.conf ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/ulpt-cupsd.sh ${PREFIX}/sbin/
	${INSTALL} -d ${CUPS_SPOOLDIR}/tmp/
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} ${CUPS_SPOOLDIR}/
	${CHMOD} -R g+w ${CUPS_SPOOLDIR}/
	${INSTALL} -d -m 775 -g ${CUPSGRP} ${CUPS_CACHEDIR}
.endif

.include <bsd.port.mk>
