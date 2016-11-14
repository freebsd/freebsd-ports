# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.9.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	qt5-
PKGNAMESUFFIX=	4
PKGNAMESUFFIX=	-designerplugin
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Designer plugin for Phonon 4

LICENSE=	LGPL21

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build qmake_build designer phonon4
CMAKE_ARGS=	-DPHONON_QT_PLUGIN_INSTALL_DIR=${PREFIX}/${QT_PLUGINDIR_REL}/designer \
		-DPHONON_BUILD_PHONON4QT5=ON

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/designer
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/qt5-phonon4/distinfo

PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/phononwidgets.so

.include <bsd.port.mk>
