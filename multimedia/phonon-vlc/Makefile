# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	0.10.1
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
PKGNAMESUFFIX=	-${PHONON_PLUGIN}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libvlc.so:multimedia/vlc

USES=		cmake pkgconfig tar:xz

USES+=		compiler:c++11-lang kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core gui widgets phonon4 \
		buildtools_build qmake_build
CMAKE_ON=	PHONON_BUILD_PHONON4QT5
PLIST_FILES=	${QT_PLUGINDIR_REL}/phonon4qt5_backend/phonon_vlc.so

PHONON_PLUGIN=	vlc
WRKSRC=		${WRKDIR}/${PORTNAME}-${PHONON_PLUGIN}-${DISTVERSION}

.include <bsd.port.mk>
