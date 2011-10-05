# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-qt
PORTVERSION=	2.2.1
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	EiskaltDC++ Direct Connect client Qt GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/eiskaltdcpp/keep_me:${PORTSDIR}/net-p2p/eiskaltdcpp-data

LIB_DEPENDS+=	eiskaltdcpp:${PORTSDIR}/net-p2p/eiskaltdcpp-lib \
		execinfo:${PORTSDIR}/devel/libexecinfo
CMAKE_ARGS+=	-DBUILD_LIB:BOOL=OFF

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	4.2+
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

OPTIONS=	ASPELL		"Build with aspell support" off \
		FREE_SPACE	"Free space bar in status panel"	on \
		DBUS_NOTIFY	"DBus notification support"	on \
		QTSCRIPT	"QtScript support"	off \
		QML	"Qt Declarative ui support" off \
		SQLITE	"SQLite support (experimental)" off \
		MINIUPNP	"UPnP support"	on

USE_QT_VER=	4
QT_COMPONENTS=	gui xml network qmake_build uic_build \
		moc_build rcc_build linguist_build
CMAKE_ARGS+=	-DUSE_QT:BOOL=ON
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DEISKALTDCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/eiskaltdcpp"
CMAKE_ARGS+=	-DCREATE_MO:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

.include <bsd.port.options.mk>

.if defined(WITH_ASPELL) && !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=on
.else
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=0
.endif

.if defined(WITH_FREE_SPACE)
CMAKE_ARGS+=	-DFREE_SPACE_BAR_C:BOOL=ON
.else
CMAKE_ARGS+=	-DFREE_SPACE_BAR_C:BOOL=OFF
.endif

.if defined(WITH_DBUS_NOTIFY) && !defined(WITHOUT_DBUS)
CMAKE_ARGS+=	-DDBUS_NOTIFY:BOOL=ON
QT_COMPONENTS+=	dbus
.else
CMAKE_ARGS+=	-DDBUS_NOTIFY:BOOL=OFF
.endif

.if defined(WITH_QTSCRIPT)
CMAKE_ARGS+=	-DUSE_JS:BOOL=ON
QT_COMPONENTS+=	script
RUN_DEPENDS+=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so:${PORTSDIR}/devel/qtscriptgenerator
PLIST_SUB+=	QTSCRIPT=""
.else
CMAKE_ARGS+=	-DUSE_JS:BOOL=OFF
PLIST_SUB+=	QTSCRIPT="@comment "
.endif

.if defined(WITH_QML)
CMAKE_ARGS+=	-DUSE_QT_QML:BOOL=ON
QT_COMPONENTS+=	declarative
.else
CMAKE_ARGS+=	-DUSE_QT_QML:BOOL=OFF
.endif

.if defined(WITH_SQLITE) && !defined(WITHOUT_SQLITE)
CMAKE_ARGS+=	-DUSE_QT_SQLITE:BOOL=ON
QT_COMPONENTS+=	sql-sqlite3
.else
CMAKE_ARGS+=	-DUSE_QT_SQLITE:BOOL=OFF
.endif

.if defined(WITH_MINIUPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=ON -DLOCAL_MINIUPNP:BOOL=OFF
.else
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF
.endif

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

.include <bsd.port.mk>
