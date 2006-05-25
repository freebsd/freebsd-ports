# New ports collection makefile for:	hplip
# Date created:		1 April 2006
# Whom:			amistry@am-productions.biz
#
# $FreeBSD$
#

PORTNAME=	hplip
PORTVERSION=	0.9.11
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

CONFLITS=	hpijs-* foomatic-filters-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-pp-build
INSTALLS_SHLIB=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	hpiod.sh hpssd.sh

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	GUI "build with Python QT" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

.if exists(${LOCALBASE}/bin/pylupdate)
WITH_GUI=      yes
.endif

.if defined(WITH_GUI)
RUN_DEPENDS+=	pylupdate:${PORTSDIR}/x11-toolkits/py-qt
.endif

post-extract:
	@${RM} -r ${WRKSRC}/data/images/CVS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/cups|${LOCALBASE}/share/cups|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/configure ${WRKSRC}/prnt/hpijs/configure
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g ; \
		s|/usr/lib|${LOCALBASE}/lib|g ; \
		s|/etc/init.d|${LOCALBASE}/etc/rc.d|g ; \
		s|/etc/sane.d|${LOCALBASE}/etc/sane.d|g ; \
		s|/etc/hp|${LOCALBASE}/etc/hp|g' \
			${WRKSRC}/Makefile.in \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/hp/|${LOCALBASE}/etc/hp/|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/base/g.py \
			${WRKSRC}/fax/backend/hpfax.py \
			${WRKSRC}/hpssd.py \
			${WRKSRC}/io/hpiod/hpiod.h \
			${WRKSRC}/prnt/hpijs/hplip_api.h \
			${WRKSRC}/prnt/hpijs/configure.in
	@${REINPLACE_CMD} -e 's|#!/usr/bin/env python|#!${LOCALBASE}/bin/python|g' \
			${WRKSRC}/*.py \
			${WRKSRC}/*/*.py \
			${WRKSRC}/*/*/*.py
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
