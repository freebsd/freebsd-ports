# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.3.10
DISTVERSIONSUFFIX=	-source
CATEGORIES=	print
MASTER_SITES=	EASYSW/${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=	-base${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Common UNIX Printing System

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	LPRng-[0-9]*

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	cupsd
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
			--with-domainsocket=${CUPS_SOCKET}

OPTIONS=	GNUTLS		"Build with GNUTLS library" on \
		PHP		"Build PHP support" off \
		PYTHON		"Build PYTHON support" off \
		LIBPAPER	"Build with libpaper support" off \
		DNSSD		"Build with DNS_SD (avahi) support" off \
		PAM		"Build with PAM support" off \
		LDAP		"Build with LDAP support" off \
		DBUS		"Build with DBUS support" off \
		XDG_OPEN	"Build with XDG_OPEN as browser" off

CUPS_ETCDIR=	${PREFIX}/etc/cups
CUPS_SPOOLDIR=	/var/spool/cups
CUPS_SOCKET?=	/var/run/cups.sock
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# file, dir ownership
CUPSGRP=	cups
CUPSOWN=	cups
CUPSSYSGRP=	wheel

.include <bsd.port.pre.mk>

.if defined(CUPS_OVERWRITE_BASE)
PLIST_SUB+=		OVERWRITE=""
.else
PLIST_SUB+=		OVERWRITE="@comment "
.endif

.if !defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--enable-gnutls --disable-openssl
LIB_DEPENDS+=		gnutls-openssl.26:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls --enable-openssl
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if defined(WITH_PHP)
CONFIGURE_ARGS+=	--with-php
USE_PHP=		yes
USE_PHP_BUILD=		yes
PLIST_SUB+=		PHP=""
.else
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=		PHP="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(WITH_LIBPAPER)
CONFIGURE_ARGS+=	--enable-libpaper
LIB_DEPENDS+=		paper.2:${PORTSDIR}/print/libpaper
.endif

.if defined(WITH_DNSSD)
CONFIGURE_ARGS+=	--enable-dnssd \
			--with-dnssd-libs=${LOCALBASE}/lib/ \
			--with-dnssd-includes=${LOCALBASE}/include/avahi-compat-libdns_sd/
LIB_DEPENDS+=		dns_sd:${PORTSDIR}/net/avahi-libdns
.else
CONFIGURE_ARGS+=	--disable-dnssd
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
PLIST_SUB+=		WITH_PAMD=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		WITH_PAMD="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if defined(WITH_XDG_OPEN)
RUN_DEPENDS+=		xdg-open:${PORTSDIR}/devel/xdg-utils
.endif

MAN1EXT=	1
MAN5EXT=	5
MAN7EXT=	7
MAN8EXT=	8

MAN1=	cancel.${MAN1EXT} \
	cups-config.${MAN1EXT} \
	cupstestdsc.${MAN1EXT} \
	cupstestppd.${MAN1EXT} \
	lp.${MAN1EXT} \
	lpoptions.${MAN1EXT} \
	lppasswd.${MAN1EXT} \
	lpq.${MAN1EXT} \
	lprm.${MAN1EXT} \
	lpr.${MAN1EXT} \
	lpstat.${MAN1EXT}
MAN5=	classes.conf.${MAN5EXT} \
	client.conf.${MAN5EXT} \
	cups-snmp.conf.${MAN5EXT} \
	cupsd.conf.${MAN5EXT} \
	mailto.conf.${MAN5EXT} \
	mime.convs.${MAN5EXT} \
	mime.types.${MAN5EXT} \
	printers.conf.${MAN5EXT} \
	subscriptions.conf.${MAN5EXT}
MAN7=	backend.${MAN7EXT} \
	filter.${MAN7EXT}
MAN8=	accept.${MAN8EXT} \
	cupsaddsmb.${MAN8EXT} \
	cups-deviced.${MAN8EXT} \
	cups-driverd.${MAN8EXT} \
	cups-lpd.${MAN8EXT} \
	cups-polld.${MAN8EXT} \
	cupsctl.${MAN8EXT} \
	cupsd.${MAN8EXT} \
	cupsenable.${MAN8EXT} \
	cupsfilter.${MAN8EXT} \
	lpadmin.${MAN8EXT} \
	lpinfo.${MAN8EXT} \
	lpmove.${MAN8EXT} \
	lpc.${MAN8EXT}

MLINKS=	accept.${MAN8EXT} reject.${MAN8EXT} \
	cupsenable.${MAN8EXT} cupsdisable.${MAN8EXT}

pre-configure::
	@${ECHO_MSG} Configuring CUPS with options:
	@${ECHO_MSG} ${CONFIGURE_ARGS} | fmt

.if defined(WITH_PAM)
post-configure:
	${GREP} -v pam_securityserver ${WRKSRC}/conf/pam.darwin  > ${WRKSRC}/conf/pam.std
.endif

post-patch:
.if defined(WITH_XDG_OPEN)
	@${REINPLACE_CMD} -e 's|htmlview|xdg-open|' ${WRKSRC}/desktop/cups.desktop
.endif
	@${REINPLACE_CMD} -e '/SILENT/d' ${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} -e '/share/s|/usr/share|${PREFIX}/share|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/cups|/usr/local/etc/cups|g' ${WRKSRC}/man/*.man*
	@${REINPLACE_CMD} -e 's|CXX="$$CC"||g ; s|-lpthreads.*;|${PTHREAD_LIBS};|g' \
		-e 's|/private/etc/pam.d|${LOCALBASE}/etc/pam.d|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

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

.include <bsd.port.post.mk>
