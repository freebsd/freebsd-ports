# New ports collection makefile for:	hplip
# Date created:		1 April 2006
# Whom:			amistry@am-productions.biz
#
# $FreeBSD$
#

PORTNAME=	hplip
PORTVERSION=	2.8.2
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hplip

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		sane.1:${PORTSDIR}/graphics/sane-backends \
		cups.2:${PORTSDIR}/print/cups-base \
		netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2 \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters

CONFLICTS=	hpijs-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-pp-build \
		--enable-foomatic-ppd-install \
		--with-icondir=${LOCALBASE}/share/applications \
		--with-cupsbackenddir=${LOCALBASE}/libexec/cups/backend \
		--with-cupsfilterdir=${LOCALBASE}/libexec/cups/filter \
		--with-drvdir=${LOCALBASE}/libexec/cups/driver

USE_LDCONFIG=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	hpssd.sh
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	GUI "build with Python QT" on

PLIST_SUB+=	PORTVERSION=${PORTVERSION} IJSVER=2.7.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

.if !defined(WITHOUT_GUI) || exists(${LOCALBASE}/bin/pylupdate)
RUN_DEPENDS+=	pylupdate:${PORTSDIR}/x11-toolkits/py-qt
CONFIGURE_ARGS+=	--enable-gui-build
.endif

post-extract:
	@${RM} -r ${WRKSRC}/data/images/CVS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/hp|${LOCALBASE}/etc/hp|g ; \
		s|/etc/sane.d|${LOCALBASE}/etc/sane.d|g' \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/check.py \
		${WRKSRC}/hpssd.py \
		${WRKSRC}/base/g.py \
		${WRKSRC}/doc/release_notes.html \
		${WRKSRC}/doc/tech_docs/man_pages/hpssd.html \
		${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/installer/distros.dat \
		${WRKSRC}/installer/core_install.py \
		${WRKSRC}/prnt/hpijs/ljzjs.cpp

	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/configure.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-dist_www7DATA install-docDATA|install-dist_www7DATA|g ; \
				s|install-dist_unrelDATA install-dist_www0DATA|install-dist_unrelDATA|g ; \
				s|install-dist_www1DATA install-dist_www21DATA||g ; \
				s|install-dist_www22DATA install-dist_www23DATA||g ; \
				s|install-dist_www241DATA install-dist_www242DATA||g ; \
				s|install-dist_www243DATA install-dist_www24DATA||g ; \
				s|install-dist_www251DATA install-dist_www252DATA||g ; \
				s|install-dist_www261DATA install-dist_www2DATA||g ; \
				s|install-dist_www3DATA install-dist_www4DATA||g ; \
				s|install-dist_www5DATA install-dist_www61DATA||g ; \
				s|install-dist_www6DATA install-dist_www7DATA||g' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|install-dist_prntSCRIPTS install-dist_rulesDATA|install-dist_prntSCRIPTS|g ; \
				s|install-hpPROGRAMS install-hplip_confDATA|install-hpPROGRAMS|g' \
		${WRKSRC}/Makefile.in
#	@${REINPLACE_CMD} -e 's|install-dist_www7DATA install-docDATA|install-dist_www7DATA|g' \
#		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldld||g ; \
			s|-ldl||g ; \
			s|-dld||g' \
		${WRKSRC}/configure \
		${WRKSRC}/configure.in \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/aclocal.m4

	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/hpssd.py

pre-su-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${LN} -sf ${PREFIX}/share/hplip/hpssd.py ${PREFIX}/sbin/hpssd
	@${MKDIR} ${PREFIX}/etc/hp
	# Auto-generate sample configuration file
	@${INSTALL_DATA} ${WRKSRC}/hplip.conf ${PREFIX}/etc/hp/hplip.conf.sample
.if !exists(${PREFIX}/etc/hp/hplip.conf)
	@${INSTALL_DATA} ${WRKSRC}/hplip.conf ${PREFIX}/etc/hp/hplip.conf
.endif
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.post.mk>
