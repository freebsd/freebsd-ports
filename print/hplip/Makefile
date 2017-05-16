# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip
PORTVERSION=	3.16.11
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Drivers and utilities for HP printers and All-in-One devices

LICENSE=	GPLv2 MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcupsimage.so:print/cups \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	cups-filters>=0:print/cups-filters \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus

CONFLICTS_INSTALL=	hpijs-[0-9]*

INSTALL_TARGET=	install-strip
USES=		jpeg libtool pkgconfig python shebangfix
USE_GNOME=	pygobject
USE_LDCONFIG=	yes
SHEBANG_GLOB=	*.py hpps pstotiff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-icondir=${DESKTOPDIR} \
		--with-systraydir=${PREFIX}/etc/xdg/autostart \
		--with-mimedir=${PREFIX}/share/cups/mime \
		--with-docdir=${DOCSDIR} \
		--with-htmldir=${DOCSDIR} \
		--with-drvdir=${PREFIX}/share/cups/drv
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS FAX SCAN SNMP X11 XSANE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT5 SCAN SNMP X11
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	doc-build

FAX_DESC=		PC Send Fax support
FAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>=0:print/py-reportlab
FAX_CONFIGURE_ENABLE=	fax-build

SCAN_DESC=		Scanning support
SCAN_LIB_DEPENDS=	libsane.so:graphics/sane-backends
SCAN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow
SCAN_CONFIGURE_ENABLE=	scan-build

SNMP_DESC=		Network/JetDirect support
SNMP_USES=		ssl
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	network-build

X11_DESC=		Graphical User Interface (Qt)
X11_CONFIGURE_ENABLE=	gui-build

XSANE_DESC=		Install XSane for scanning (implies SCAN)
XSANE_IMPLIES=		SCAN
XSANE_RUN_DEPENDS=	xsane:graphics/xsane

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4} && ${PORT_OPTIONS:MX11}
USES+=			pyqt:4
USE_PYQT=		core_run dbussupport_run gui_run sip
CONFIGURE_ARGS+=	--enable-qt4
.else
CONFIGURE_ARGS+=	--disable-qt4
.endif

.if ${PORT_OPTIONS:MQT5} && ${PORT_OPTIONS:MX11}
USES+=			pyqt:5
USE_PYQT=		core_run dbussupport_run gui_run sip widgets_run
CONFIGURE_ARGS+=	--enable-qt5
.else
CONFIGURE_ARGS+=	--disable-qt5
.endif

.if ${PORT_OPTIONS:MX11} && ! ${PORT_OPTIONS:MQT4} && ! ${PORT_OPTIONS:MQT5}
BROKEN=			The X11 option requires one of the QT4 or QT5 options
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldld||g;' \
		-e 's|-ldl||g' \
		-e 's,-lusb-1.0,-lusb,g' \
		-e 's,libusb-1.0/libusb.h,libusb.h,g' \
		${WRKSRC}/configure \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/[[:space:]]install-dist_rulesDATA/ s,install-dist_rulesDATA,,' \
		-e '/[[:space:]]install-dist_rulessystemDATA/ s,install-dist_rulessystemDATA,,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,/etc/hp,${PREFIX}&,g' \
		-e 's,/etc/cups,${LOCALBASE}&,g' \
		-e 's,/etc/init.d,${LOCALBASE}/etc/rc.d,g' \
		-e 's,/etc/sane.d,${LOCALBASE}&,g' \
		-e 's,/usr/share,${LOCALBASE}/share,g' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/base/codes.py \
		${WRKSRC}/base/g.py \
		${WRKSRC}/base/password.py \
		${WRKSRC}/base/pkit.py \
		${WRKSRC}/base/queues.py \
		${WRKSRC}/base/services.py \
		${WRKSRC}/base/utils.py \
		${WRKSRC}/check.py \
		${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/fax/coverpages.py \
		${WRKSRC}/fax/filters/pstotiff \
		${WRKSRC}/hplip.list.in \
		${WRKSRC}/installer/core_install.py \
		${WRKSRC}/installer/dcheck.py \
		${WRKSRC}/installer/pluginhandler.py \
		${WRKSRC}/logcapture.py \
		${WRKSRC}/prnt/cups.py \
		${WRKSRC}/prnt/filters/hpps \
		${WRKSRC}/prnt/hpcups/HPCupsFilter.cpp \
		${WRKSRC}/prnt/hpijs/globals.cpp \
		${WRKSRC}/prnt/hpijs/hpcupsfax.cpp \
		${WRKSRC}/prnt/hpijs/hpijs.cpp \
		${WRKSRC}/ui/devmgr4.py \
		${WRKSRC}/ui4/devmgr5.py
	@${REINPLACE_CMD} -e 's/umask(0)/umask(0o022)/' \
		-e 's/umask(0o111)/umask(0o133)/' \
		${WRKSRC}/base/os_utils.py \
		${WRKSRC}/base/validation.py \
		${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/hpdio.py \
		${WRKSRC}/installer/pluginhandler.py

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/hp/hplip.conf \
		${STAGEDIR}${PREFIX}/etc/hp/hplip.conf.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/ui4/plugins
	${MKDIR} ${STAGEDIR}/var/lib/hp

post-install-SCAN-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/sane.d/dll.d
	${MV} ${STAGEDIR}${PREFIX}/etc/sane.d/dll.conf \
		${STAGEDIR}${PREFIX}/etc/sane.d/dll.d/hpaio

.include <bsd.port.mk>
