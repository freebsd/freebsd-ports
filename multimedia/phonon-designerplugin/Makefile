# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	4.10.1
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for Phonon

LICENSE=	LGPL21

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_PKGNAMESUFFIX=	-designerplugin-qt4
qt5_PKGNAMESUFFIX=	-designerplugin-qt5

USES=		cmake:insource tar:xz

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		kde:4 qt:4
USE_QT=		corelib designer gui phonon \
		qmake_build moc_build rcc_build uic_build
PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/libphononwidgets.so
.  else
USES+=		kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core designer gui phonon4 widgets xml \
		buildtools_build qmake_build
CMAKE_ON=	PHONON_BUILD_PHONON4QT5
PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/phononwidgets.so
.  endif

CMAKE_ARGS=	-DPHONON_QT_PLUGIN_INSTALL_DIR=${PREFIX}/${QT_PLUGINDIR_REL}/designer

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/phonon/distinfo

.include <bsd.port.mk>
