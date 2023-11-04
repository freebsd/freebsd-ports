PORTNAME=	phonon
DISTVERSION=	0.12.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
PKGNAMESUFFIX=	-${PHONON_PLUGIN}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon
WWW=		https://userbase.kde.org/Phonon

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libvlc.so:multimedia/vlc

USES=		cmake pkgconfig tar:xz

USES+=		compiler:c++11-lang kde:5 qt:5
USE_KDE=	ecm:build
USE_QT=		core gui phonon4 widgets \
		buildtools:build qmake:build
CMAKE_ON=	PHONON_BUILD_QT5
CMAKE_OFF=	PHONON_BUILD_QT6

PHONON_PLUGIN=	vlc

.include <bsd.port.mk>
