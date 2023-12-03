PORTNAME=	phonon
DISTVERSION=	4.12.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/phonon
PKGNAMESUFFIX=	-designerplugin-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for Phonon
WWW=		https://userbase.kde.org/Phonon

LICENSE=	LGPL21

USES=		cmake:insource compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	phonon ecm:build
USE_QT=		core designer gui uiplugin widgets xml \
		buildtools:build qmake:build
CMAKE_ON=	PHONON_BUILD_QT5
CMAKE_OFF=	PHONON_BUILD_QT6
PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/phonon4qt5widgets.so

BUILD_WRKSRC=	${WRKSRC}/designer5
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/phonon/distinfo

.include <bsd.port.mk>
