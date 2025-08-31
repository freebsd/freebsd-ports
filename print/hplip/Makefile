PORTNAME=	hplip
PORTVERSION=	3.24.4
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Drivers and utilities for HP printers and All-in-One devices
WWW=		https://developers.hp.com/hp-linux-imaging-and-printing

LICENSE=	GPLv2+ MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcupsimage.so:print/cups \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	cups-filters>=0:print/cups-filters \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.0.1:sysutils/py-distro@${PY_FLAVOR}

USES=		dos2unix gnome jpeg libtool localbase pkgconfig python \
		shebangfix
USE_GNOME=	pygobject3:run
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	fax/filters/cdmfax/jetlib.cpp \
		scan/sane/OrbliteScan/LinuxCommon.h scan/sane/orblite.c
SHEBANG_GLOB=	*.py hpps pstotiff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-icondir=${DESKTOPDIR} \
		--with-systraydir=${PREFIX}/etc/xdg/autostart \
		--with-mimedir=${PREFIX}/share/cups/mime \
		--with-docdir=${DOCSDIR} \
		--with-htmldir=${DOCSDIR} \
		--with-drvdir=${PREFIX}/share/cups/drv \
		--disable-imageProcessor-build \
		--disable-qt4
CONFIGURE_ENV+=	PYTHONINCLUDEDIR=${PYTHON_INCLUDEDIR}
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
INSTALL_TARGET=	install-strip

DEBUG_FLAGS+=	-UNDEBUG -DHP_DEBUG -DHPIP_DEBUG -DHPMUD_DEBUG -DHTTP_DEBUG \
		-DAVAHI_DEBUG -DBB_LEDM_DEBUG -DESCL_DEBUG -DHPAIO_DEBUG \
		-DSCLPML_DEBUG

OPTIONS_DEFINE=		DOCS FAX NETWORK SCAN X11 XSANE
OPTIONS_DEFAULT=	NETWORK SCAN X11
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	doc-build

FAX_DESC=		PC Send Fax support
FAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>=0:print/py-reportlab@${PY_FLAVOR}
FAX_CONFIGURE_ENABLE=	fax-build

SCAN_DESC=		Scanning support
SCAN_RUN_DEPENDS=	${PY_PILLOW}
SCAN_LIB_DEPENDS=	libsane.so:graphics/sane-backends
SCAN_CONFIGURE_ENABLE=	scan-build

NETWORK_DESC=		Network/JetDirect support
NETWORK_USES=		ssl
NETWORK_LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
			libnetsnmp.so:net-mgmt/net-snmp
NETWORK_CONFIGURE_ENABLE=	network-build

X11_DESC=		Graphical User Interface (Qt)
X11_CONFIGURE_ENABLE=	gui-build qt5
X11_USES=		pyqt:5
X11_USE=		PYQT=pyqt5:run

XSANE_DESC=		Install XSane for scanning (implies SCAN)
XSANE_IMPLIES=		SCAN
XSANE_RUN_DEPENDS=	xsane:graphics/xsane

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/base/g.py \
		${WRKSRC}/base/utils.py \
		${WRKSRC}/base/queues.py \
		${WRKSRC}/check.py \
		${WRKSRC}/common/utils.c \
		${WRKSRC}/doc/troubleshooting.html \
		${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/fax/filters/pstotiff \
		${WRKSRC}/FindPPD.cpp \
		${WRKSRC}/installer/core_install.py \
		${WRKSRC}/installer/pluginhandler.py \
		${WRKSRC}/logcapture.py \
		${WRKSRC}/prnt/hpps/hppsfilter.c \
		${WRKSRC}/prnt/cups.py \
		${WRKSRC}/prnt/hpijs/hpcupsfax.cpp \
		${WRKSRC}/prnt/hpijs/globals.cpp \
		${WRKSRC}/prnt/hpijs/foomatic-rip-hplip \
		${WRKSRC}/prnt/filters/hpps \
		${WRKSRC}/ui5/scandialog.py \
		${WRKSRC}/ui5/devmgr5.py \

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/hp-pkservice \
		${STAGEDIR}${PREFIX}/bin/hp-uninstall \
		${STAGEDIR}${PREFIX}/bin/hp-upgrade \
		${STAGEDIR}${DOCSDIR}/uninstalling.html \
		${STAGEDIR}${DOCSDIR}/upgrading.html \
		${STAGEDIR}${DATADIR}/dat2drv \
		${STAGEDIR}${DATADIR}/locatedriver \
		${STAGEDIR}${DATADIR}/pkservice.py \
		${STAGEDIR}${DATADIR}/uninstall.py \
		${STAGEDIR}${DATADIR}/upgrade.py
	${MV} ${STAGEDIR}${PREFIX}/etc/hp/hplip.conf \
		${STAGEDIR}${PREFIX}/etc/hp/hplip.conf.sample
	${MKDIR} ${STAGEDIR}/var/lib/hp

post-install-X11-on:
.for s in 16 32 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${LN} ${STAGEDIR}${DATADIR}/data/images/${s}x${s}/hp_logo.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
.endfor

.include <bsd.port.mk>
