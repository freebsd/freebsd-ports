# $FreeBSD$

PORTNAME=	telepathy-logger-qt
DISTVERSION=	17.09.0
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION:R}/src
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt binding for Telepathy Logger

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libtelepathy-qt5.so:net-im/telepathy-qt

USES=		bison:build cmake compiler:c++11-lang gnome kde:5 \
		pkgconfig python:3.5+,build qt:5 tar:xz
USE_GNOME=	glib20 libxml2
USE_KDE=	ecm
USE_QT=		core buildtools_build dbus network qmake_build xml
CMAKE_ARGS=	-DUSE_COMMON_CMAKE_PACKAGE_CONFIG_DIR:BOOL=True
USE_LDCONFIG=	yes

.include <bsd.port.mk>
