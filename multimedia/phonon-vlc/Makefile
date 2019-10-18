# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	0.11.1
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

PHONON_PLUGIN=	vlc

.include <bsd.port.mk>
