# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp-qt
PORTVERSION=	2.2.4
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	EiskaltDC++ Direct Connect client Qt GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/eiskaltdcpp/keep_me:${PORTSDIR}/net-p2p/eiskaltdcpp-data

LIB_DEPENDS+=	eiskaltdcpp:${PORTSDIR}/net-p2p/eiskaltdcpp-lib \
		execinfo:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS+=	chrpath:${PORTSDIR}/devel/chrpath

CMAKE_ARGS+=	-DBUILD_LIB:BOOL=OFF

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	yes
USES=		cmake gettext
USE_OPENSSL=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

OPTIONS_DEFINE=	ASPELL FREE_SPACE DBUS_NOTIFY QTSCRIPT QML SQLITE MINIUPNP
OPTIONS_DEFAULT=	FREE_SPACE DBUS_NOTIFY MINIUPNP
FREE_SPACE_DESC=	Free space bar in status panel
DBUS_NOTIFY_DESC=	DBus notification support
QTSCRIPT_DESC=		QtScript support
QML_DESC=		Qt Declarative ui support
SQLITE_DESC=		SQLite support (experimental)
MINIUPNP_DESC=		UPnP support

USE_QT4=	gui xml network qmake_build uic_build \
		moc_build rcc_build linguist_build
CMAKE_ARGS+=	-DUSE_QT:BOOL=ON
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DEISKALTDCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/eiskaltdcpp"
CMAKE_ARGS+=	-DCREATE_MO:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=on
.else
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=0
.endif

.if ${PORT_OPTIONS:MFREE_SPACE}
CMAKE_ARGS+=	-DFREE_SPACE_BAR_C:BOOL=ON
.else
CMAKE_ARGS+=	-DFREE_SPACE_BAR_C:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDBUS_NOTIFY}
CMAKE_ARGS+=	-DDBUS_NOTIFY:BOOL=ON
USE_QT4+=	dbus
.else
CMAKE_ARGS+=	-DDBUS_NOTIFY:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MQTSCRIPT}
CMAKE_ARGS+=	-DUSE_JS:BOOL=ON
USE_QT4+=	script
RUN_DEPENDS+=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so:${PORTSDIR}/devel/qtscriptgenerator
PLIST_SUB+=	QTSCRIPT=""
.else
CMAKE_ARGS+=	-DUSE_JS:BOOL=OFF
PLIST_SUB+=	QTSCRIPT="@comment "
.endif

.if ${PORT_OPTIONS:MQML}
CMAKE_ARGS+=	-DUSE_QT_QML:BOOL=ON
USE_QT4+=	declarative
.else
CMAKE_ARGS+=	-DUSE_QT_QML:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSQLITE}
CMAKE_ARGS+=	-DUSE_QT_SQLITE:BOOL=ON
USE_QT4+=	sql-sqlite3
.else
CMAKE_ARGS+=	-DUSE_QT_SQLITE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMINIUPNP}
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=ON -DLOCAL_MINIUPNP:BOOL=OFF
.else
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF
.endif

post-build:
	${LOCALBASE}/bin/chrpath -r "${_GCC_RUNTIME}" "${WRKSRC}/${PORTNAME}/${PORTNAME}"

.include <bsd.port.mk>
