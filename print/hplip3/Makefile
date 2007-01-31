# New ports collection makefile for:	hplip
# Date created:		1 April 2006
# Whom:			amistry@am-productions.biz
#
# $FreeBSD$
#

PORTNAME=	hplip
PORTVERSION=	1.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hplip

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		sane.1:${PORTSDIR}/graphics/sane-backends \
		cups.2:${PORTSDIR}/print/cups-base \
		usb:${PORTSDIR}/devel/libusb \
		netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp

CONFLICTS=	hpijs-* foomatic-filters-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-pp-build
USE_LDCONFIG=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	hpiod.sh hpssd.sh

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	GUI "build with Python QT" on

PLIST_SUB+=	PORTVERSION=${PORTVERSION} IJSVER=2.7.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.if !defined(WITHOUT_GUI) || exists(${LOCALBASE}/bin/pylupdate)
RUN_DEPENDS+=	pylupdate:${PORTSDIR}/x11-toolkits/py-qt
CONFIGURE_ARGS+=	--enable-gui-build
.endif

post-extract:
	@${RM} -r ${WRKSRC}/data/images/CVS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/cups|${LOCALBASE}/share/cups|g ; \
		s|/usr/lib/cups/backend|${LOCALBASE}/libexec/cups/backend|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/configure ${WRKSRC}/prnt/hpijs/configure
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g ; \
		s|/usr/lib|${LOCALBASE}/lib|g ; \
		s|/etc/init.d|${LOCALBASE}/etc/rc.d|g ; \
		s|/etc/sane.d|${LOCALBASE}/etc/sane.d|g ; \
		s|/etc/hp|${LOCALBASE}/etc/hp|g' \
			${WRKSRC}/Makefile.in \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g ; \
			s|/usr/lib|${LOCALBASE}/lib|g' \
			${WRKSRC}/prnt/hpijs/foomatic-rip
	@${REINPLACE_CMD} -e 's|/etc/hp/|${LOCALBASE}/etc/hp/|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/base/g.py \
			${WRKSRC}/fax/backend/hpfax.py \
			${WRKSRC}/hpssd.py \
			${WRKSRC}/io/hpiod/hpiod.h \
			${WRKSRC}/api/hplip_api.h \
			${WRKSRC}/prnt/hpijs/configure.in
	@${REINPLACE_CMD} -e 's|#!/usr/bin/env python|#!${LOCALBASE}/bin/python|g' \
			${WRKSRC}/*.py \
			${WRKSRC}/*/*.py \
			${WRKSRC}/*/*/*.py
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-data-am: install-docDATA|install-data-am:|g' \
		${WRKSRC}/prnt/hpijs/Makefile.in
	@${REINPLACE_CMD} -e 's|install-dist_xmlDATA install-docDATA|install-dist_xmlDATA|g' \
		${WRKSRC}/Makefile.in
.endif

pre-su-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${LN} -sf ${PREFIX}/share/hplip/hpssd.py ${PREFIX}/sbin/hpssd
	@${LN} -sf ${PREFIX}/bin/foomatic-rip \
		${PREFIX}/libexec/cups/filter/foomatic-rip
	@${MKDIR} ${PREFIX}/etc/hp
	# Auto-generate sample configuration file
	@${ECHO} "home=${PREFIX}/share/hplip" >> ${WRKSRC}/hplip.conf
	@${ECHO} "ppd=${PREFIX}/share/ppd" >> ${WRKSRC}/hplip.conf
	@${INSTALL_DATA} ${WRKSRC}/hplip.conf ${PREFIX}/etc/hp/hplip.conf.sample
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.post.mk>
