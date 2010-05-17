# New ports collection makefile for:	hplip
# Date created:		1 April 2006
# Whom:			amistry@am-productions.biz
#
# $FreeBSD$
#

PORTNAME=	hplip
PORTVERSION=	3.10.2
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	chris@officialunix.com
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		sane.1:${PORTSDIR}/graphics/sane-backends \
		cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2 \
		espgs:${PORTSDIR}/print/cups-pstoraster \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters \
		mDNSClientPosix:${PORTSDIR}/net/mDNSResponder

LATEST_LINK=	${PORTNAME}3
CONFLICTS=	hpijs-[0-9]* hplip-2*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-pp-build \
		--enable-foomatic-ppd-install \
		--enable-foomatic-rip-hplip-install \
		--enable-hpijs-install \
		--with-icondir=${LOCALBASE}/share/applications \
		--with-cupsbackenddir=${LOCALBASE}/libexec/cups/backend \
		--with-cupsfilterdir=${LOCALBASE}/libexec/cups/filter \
		--with-drvdir=${LOCALBASE}/libexec/cups/driver \
		--with-hpppddir=${LOCALBASE}/share/ppd/HP \
		--with-mimedir=${LOCALBASE}/etc/cups \
		--with-docdir=${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	25+
USE_RC_SUBR=	hpssd
MAKE_JOBS_SAFE=	yes
SUB_FILES=	pkg-message
USE_DOS2UNIX=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lcompat

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	QT "Build QT4 gui" off \
		DBUS "D-Bus support (required for fax tools)" off \
		XSANE "Scanning support via XSane" off \
		SNMP "Support for Simple Network Management Protocol" off

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

.if defined(WITH_SNMP) && (${ARCH} == i386)
BROKEN=	can't link with libsnmp, net-mgmt/net-snmp should be fixed first
.endif

.if !defined(WITHOUT_QT)
USE_QT_VER=	4
QT_COMPONENTS=	gui
CONFIGURE_ARGS+=	--enable-qt4
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
LIB_DEPENDS+=	pyglib-2.0:${PORTSDIR}/devel/py-gobject
.endif

.if !defined(WITHOUT_DBUS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbus
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
# fax added as, no dbus no fax
CONFIGURE_ARGS+=	--enable-dbus-build \
			--enable-fax-build
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--disable-dbus-build \
			--disable-fax-build
PLIST_SUB+=	FAX="@comment "
.endif

.if !defined(WITHOUT_XSANE)
RUN_DEPENDS+=	xsane:${PORTSDIR}/graphics/xsane
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-network-build
.else
CONFIGURE_ARGS+=	--disable-network-build
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-doc-build=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/hp|${LOCALBASE}/etc/hp|g ; \
			s|/etc/sane.d|${LOCALBASE}/etc/sane.d|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/check.py ${WRKSRC}/hpssd.py \
		${WRKSRC}/base/g.py ${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/installer/distros.dat \
		${WRKSRC}/installer/core_install.py \
		${WRKSRC}/prnt/hpijs/ljzjs.cpp \
		${WRKSRC}/prnt/hpijs/globals.cpp \
		${WRKSRC}/ui/devmgr4.py \
		${WRKSRC}/ui4/devmgr5.py
	@${REINPLACE_CMD} -e 's|/etc/dbus-1/system.d|${LOCALBASE}/etc/dbus-1/system.d|g ; \
			s|/usr/share/dbus-1/system-services|${LOCALBASE}/share/dbus-1/system-services|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|/etc/xdg|${PREFIX}&|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|install-dist_prntSCRIPTS install-dist_rulesDATA|install-dist_prntSCRIPTS|g ; \
			s|install-hpPROGRAMS install-hplip_confDATA|install-hpPROGRAMS|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldld||g; s|-ldl||g; s|-dld||g' \
		${WRKSRC}/configure \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/hpssd.py
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/[[:space:]]install-docDATA/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${LN} -sf ${PREFIX}/share/hplip/hpssd.py ${PREFIX}/sbin/hpssd
	${INSTALL_DATA} ${WRKSRC}/hplip-systray.desktop ${PREFIX}/etc/xdg/autostart/hplip-systray.desktop
	${MKDIR} ${PREFIX}/etc/hp
	${INSTALL_DATA} ${WRKSRC}/hplip.conf ${PREFIX}/etc/hp/hplip.conf.sample
	if [ ! -f ${PREFIX}/etc/hp/hplip.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/hp/hplip.conf.sample \
			${PREFIX}/etc/hp/hplip.conf; \
	fi
	${ECHO_CMD} hpaio >> ${PREFIX}/etc/sane.d/dll.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
