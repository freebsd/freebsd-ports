# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.4.3
DISTVERSIONSUFFIX=	-source
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	EASYSW/${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=	${CUPS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Common UNIX Printing System: ${COMMENT2}

CONFLICTS=	LPRng-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
DSOFLAGS=	-Wl,-rpath,${PREFIX}/lib -L${PREFIX}/lib ${LDFLAGS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" DSOFLAGS="${DSOFLAGS}"
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
			--enable-ssl

OPTIONS?=	GNUTLS		"Build with GNUTLS library" on \
		PHP		"Build PHP support" off \
		PYTHON		"Build PYTHON support" off \
		LIBPAPER	"Build with libpaper support" off \
		DNSSD		"Build with DNS_SD (avahi) support" off \
		PAM		"Build with PAM support" off \
		LDAP		"Build with LDAP support" off \
		DBUS		"Build with DBUS support" off \
		LIBUSB		"Build with USB support" off \
		GHOSTSCRIPT	"Build pdftops with GHOSTSCRIPT" on \
		XPDF		"Build pdftops with XPDF" off \
		XDG_OPEN	"Build with XDG_OPEN as browser" off

CUPS_ETCDIR=	${PREFIX}/etc/cups
CUPS_SPOOLDIR=	/var/spool/cups
CUPS_SOCKET?=	/var/run/cups.sock
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# file, dir ownership
CUPSGRP=	cups
CUPSOWN=	cups
CUPSSYSGRP=	wheel
# GROUPS/USERS does not work here
#GROUPS=	cups
#USERS=		cups

.include <bsd.port.pre.mk>

.if defined(CUPS_CLIENT)
CUPS_SUFFIX=	-client
COMMENT2=	Library cups
INSTALL_WRKSRC=	${WRKSRC}/cups
PLIST=		${MASTERDIR}/pkg-plist.client
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.client
.elif defined(CUPS_IMAGE)
CUPS_SUFFIX=	-image
LIB_DEPENDS+=	cups.2:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
COMMENT2=	Library cupsimage
CONFIGURE_ARGS+=	--disable-pdftops
INSTALL_WRKSRC=	${WRKSRC}/filter
PLIST=		${MASTERDIR}/pkg-plist.image
USE_LDCONFIG=	yes
PKGMESSAGE=	${NONEXISTENT}
DESCR=		${MASTERDIR}/pkg-descr.image
.else
CONFLICTS+=	cupsddk-*
CUPS_SUFFIX=	-base
LIB_DEPENDS+=	cups.2:${PORTSDIR}/${PKGCATEGORY}/cups-client \
		cupsimage.2:${PORTSDIR}/${PKGCATEGORY}/cups-image
# force build if old cups is installed.
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcups.a:${PORTSDIR}/${PKGCATEGORY}/cups-client
COMMENT2=	Server
USE_RC_SUBR=	cupsd
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

.if !defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--disable-openssl --enable-gnutls
CONFIGURE_ENV+=		PKGCONFIG="${LOCALBASE}/bin/pkg-config"
LIB_DEPENDS+=		gnutls-openssl.40:${PORTSDIR}/security/gnutls
BUILD_DEPENDS+=		pkg-config:${PORTSDIR}/devel/pkg-config
.else
CONFIGURE_ARGS+=	--disable-gnutls --enable-openssl
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_PHP)
CONFIGURE_ARGS+=	--with-php
USE_PHP=		yes
USE_PHP_BUILD=		yes
PLIST_SUB+=		PHP=""
.else
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=		PHP="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && !defined(WITHOUT_GHOSTSCRIPT)
.if defined(WITH_XPDF)
IGNORE=			"Pick ghostscript or xpdf, not both"
.endif
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--enable-pdftops --with-pdftops=${LOCALBASE}/bin/gs
PLIST_SUB+=		WITH_PDFTOPS=""
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_XPDF)
BUILD_DEPENDS+=		pdftops:${PORTSDIR}/graphics/xpdf
RUN_DEPENDS+=		pdftops:${PORTSDIR}/graphics/xpdf
CONFIGURE_ARGS+=	--enable-pdftops --with-pdftops=${LOCALBASE}/bin/pdftops
PLIST_SUB+=		WITH_PDFTOPS=""
.else
PLIST_SUB+=		WITH_PDFTOPS="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_LIBPAPER)
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		paper.2:${PORTSDIR}/print/libpaper
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_DNSSD)
CONFIGURE_ARGS+=	--enable-dnssd \
			--with-dnssd-libs=${LOCALBASE}/lib/ \
			--with-dnssd-includes=${LOCALBASE}/include/avahi-compat-libdns_sd/
LIB_DEPENDS+=		dns_sd:${PORTSDIR}/net/avahi-libdns
.else
CONFIGURE_ARGS+=	--disable-dnssd
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
PLIST_SUB+=		WITH_PAMD=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		WITH_PAMD="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
PLIST_SUB+=		WITH_DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus
PLIST_SUB+=		WITH_DBUS="@comment "
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_XDG_OPEN)
RUN_DEPENDS+=		xdg-open:${PORTSDIR}/devel/xdg-utils
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_LIBUSB) && ${OSVERSION}>800062
CPPFLAGS+=		-I/usr/include
LDFLAGS+=		-L/usr/lib
.elif !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE) && defined(WITH_LIBUSB) && ${OSVERSION}<800063
LIB_DEPENDS+=		usb:${PORTSDIR}/devel/libusb
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if defined(CUPS_CLIENT)
MAN1=	cups-config.1
.elif defined(CUPS_IMAGE)
.else
MAN1=	cancel.1 \
	cupstestdsc.1 \
	cupstestppd.1 \
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
	mailto.conf.5 \
	mime.convs.5 \
	mime.types.5 \
	ppdcfile.5 \
	printers.conf.5 \
	subscriptions.conf.5
MAN7=	backend.7 \
	drv.7 \
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
.endif

pre-configure::
	@${ECHO_MSG} Configuring CUPS with options:
	@${ECHO_MSG} ${CONFIGURE_ARGS} | fmt

post-patch:
.if (${OSVERSION} >= 700000) || defined(WITH_PIEAMD64)
.if ${ARCH} == "amd64" || defined(WITH_PIEAMD64)
	@${REINPLACE_CMD} -e 's|@PIEFLAGS@||' ${WRKSRC}/Makedefs.in
.endif
.endif
.if defined(WITH_XDG_OPEN)
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
		-e 's|cups filter |cups |' \
		-e 's|backend berkeley cgi-bin driver locale man monitor||' \
		-e 's|notifier ppdc scheduler systemv test ||' \
		-e 's|$$.PHPDIR. ||' \
		-e 's|conf data doc $$.FONTS.ppd templates||' \
		-e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/Makefile
.elif defined(CUPS_IMAGE)
	@${REINPLACE_CMD} \
		-e 's|cups filter |filter |' \
		-e 's|backend berkeley cgi-bin driver locale man monitor||' \
		-e 's|notifier ppdc scheduler systemv test ||' \
		-e 's|$$.PHPDIR. ||' \
		-e 's|conf data doc $$.FONTS.ppd templates||' \
		-e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} \
		-e 's|cups filter backend|backend|' \
		-e 's|$$.INSTALL_SCRIPT. cups-config|echo skip: cups-config|' \
		-e 's|/usr/share|${PREFIX}/share|g' \
		-e 's|installhdrs$$||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|cups-config.$$.MAN1EXT. ||' \
		${WRKSRC}/man/Makefile
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

.if defined(CUPS_IMAGE)
post-install:
	${INSTALL_DATA} ${WRKSRC}/cups/raster.h ${PREFIX}/include/cups/
.endif

.if !defined(CUPS_CLIENT) && !defined(CUPS_IMAGE)
post-build:
	cd ${WRKSRC}/filter && ${MAKE} pdftops

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

post-install:
.if !defined(WITHOUT_GHOSTSCRIPT) || defined(WITH_XPDF)
	${INSTALL_PROGRAM} ${WRKSRC}/filter/pdftops ${PREFIX}/libexec/cups/filter/
.endif
	${INSTALL} -d ${CUPS_ETCDIR}/
	${CP} -p ${WRKSRC}/conf/snmp.conf ${WRKSRC}/conf/snmp.conf.N
.for f in cupsd.conf mime.convs mime.types snmp.conf
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${CUPS_ETCDIR}/${f}.N
	cd ${CUPS_ETCDIR}/; if test ! -f ${f}; then ${CP} -p ${f}.N ${f}; fi
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/lpt-cupsd.conf ${EXAMPLESDIR}/
	${INSTALL} -d ${CUPS_SPOOLDIR}/tmp/
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} ${CUPS_SPOOLDIR}/
	${CHMOD} -R g+w ${CUPS_SPOOLDIR}/
	${INSTALL} -d /var/cache/cups/
	${CHOWN} root:${CUPSGRP} /var/cache/cups/
.endif

.if defined(CUPS_CLIENT)
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cups-config ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/cups/libcups.a ${PREFIX}/lib/
	${INSTALL_MAN} ${WRKSRC}/man/cups-config.man ${PREFIX}/man/man1/cups-config.1
.endif

.include <bsd.port.post.mk>
