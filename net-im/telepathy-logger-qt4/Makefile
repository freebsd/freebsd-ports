# $FreeBSD$

PORTNAME=	telepathy-logger-qt4
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	KDE/stable/${PORTNAME:C/4$//}/${PORTVERSION}/src
DISTNAME=	${PORTNAME:C/4$//}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt binding for Telepathy Logger

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libtelepathy-qt4.so:net-im/telepathy-qt@qt4

USES=		bison:build cmake pkgconfig python:2.7,build qt:4 tar:bzip2
USE_GNOME=	glib20 libxml2
USE_GSTREAMER=	qt4
USE_QT=		corelib dbus moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DUSE_COMMON_CMAKE_PACKAGE_CONFIG_DIR:BOOL=True
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/$${QTGLIB_INCLUDE_DIR}/ s,)$$, ${LOCALBASE}/include),' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/$${GOBJECT_LIBRARIES}/ s,$$, -L${LOCALBASE}/lib,' \
		-e 's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/TelepathyLoggerQt4/CMakeLists.txt

.include <bsd.port.mk>
