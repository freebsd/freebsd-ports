# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	0.9.0
CATEGORIES=	multimedia
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}
PKGNAMEPREFIX=	qt5-
PKGNAMESUFFIX=	-vlc
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon 4 Qt 5

LIB_DEPENDS=	libvlc.so:multimedia/vlc

WRKSRC=		${WRKDIR}/${DISTNAME:S/-backend//}

USES=		cmake:outsource kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	core gui widgets phonon4 \
		buildtools_build qmake_build
CMAKE_ARGS=	-DPHONON_BUILD_PHONON4QT5=ON

PLIST_FILES=	${QT_PLUGINDIR_REL}/phonon4qt5_backend/phonon_vlc.so

.include <bsd.port.mk>
