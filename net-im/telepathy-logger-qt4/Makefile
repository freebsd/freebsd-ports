# $FreeBSD$

PORTNAME=	telepathy-logger-qt4
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/kde-telepathy/${PORTVERSION}/src
DISTNAME=	${PORTNAME:C/4$//}-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt binding for Telepathy Logger

LICENSE=	LGPL21

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4

USE_GNOME=	glib20 libxml2
USE_GSTREAMER=	qt4
USE_KDE4=	# empty
USE_PYTHON_BUILD=	yes
USE_QT4=	corelib dbus moc_build qmake_build rcc_build uic_build
USES=		bison:build cmake pkgconfig
USE_BZIP2=	yes
CMAKE_ARGS=	-DUSE_COMMON_CMAKE_PACKAGE_CONFIG_DIR:BOOL=True
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/FIND_PROGRAM/ s,qmake ,,' \
		${WRKSRC}/cmake/modules/FindQt.cmake
	@${REINPLACE_CMD} -e '/$${QTGLIB_INCLUDE_DIR}/ s,)$$, ${LOCALBASE}/include),' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/$${GOBJECT_LIBRARIES}/ s,$$, -L${LOCALBASE}/lib,' \
		-e 's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/TelepathyLoggerQt4/CMakeLists.txt

.include <bsd.port.mk>
