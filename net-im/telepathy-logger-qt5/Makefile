PORTNAME=	telepathy-logger-qt
DISTVERSION=	17.09.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION:R}/src
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt binding for Telepathy Logger
WWW=		https://community.kde.org/KTp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libtelepathy-qt5.so:net-im/telepathy-qt

USES=		cmake compiler:c++11-lang gnome kde:5 pkgconfig qt:5 tar:xz \
		bison:build python:build
USE_CXXSTD=	c++11
USE_GNOME=	glib20 libxml2
USE_KDE=	ecm:build
USE_QT=		core dbus network xml \
		buildtools:build qmake:build
CMAKE_ARGS=	-DUSE_COMMON_CMAKE_PACKAGE_CONFIG_DIR:BOOL=True
USE_LDCONFIG=	yes

.include <bsd.port.mk>
