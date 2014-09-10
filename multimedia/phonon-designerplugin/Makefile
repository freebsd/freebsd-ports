# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.7.2
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-designerplugin
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for Phonon

LICENSE=	LGPL21

USE_QT4=	phonon designer \
		qmake_build moc_build rcc_build uic_build
USES=		cmake tar:xz
CMAKE_ARGS=	-DPHONON_QT_PLUGIN_INSTALL_DIR=${PREFIX}/${QT_PLUGINDIR_REL}/designer

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/phonon/distinfo

PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/libphononwidgets.so

.include <bsd.port.mk>
