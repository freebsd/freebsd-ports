# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	4.11.1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/phonon
PKGNAMESUFFIX=	-designerplugin-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for Phonon

LICENSE=	LGPL21

USES=		cmake:insource compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core designer gui phonon4 widgets xml \
		buildtools_build qmake_build
CMAKE_ON=	PHONON_BUILD_PHONON4QT5
PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/phononwidgets.so

CMAKE_ARGS=	-DPHONON_QT_PLUGIN_INSTALL_DIR=${PREFIX}/${QT_PLUGINDIR_REL}/designer

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/phonon/distinfo

.include <bsd.port.mk>
