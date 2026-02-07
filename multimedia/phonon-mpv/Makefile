PORTNAME=	phonon-mpv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	multimedia kde
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	mpv backend for Phonon
WWW=		https://github.com/OpenProgger/phonon-mpv

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake compiler:c++17-lang kde:6 pkgconfig \
		qt:6 tar:xz
USE_KDE=	phonon ecm:build
USE_QT=		base tools:build

USE_GITHUB=	yes
GH_ACCOUNT=	OpenProgger

CMAKE_ON=	PHONON_BUILD_QT6
CMAKE_OFF=	PHONON_BUILD_QT5

PLIST_FILES=	${QT_PLUGINDIR}/phonon4qt6_backend/phonon_mpv_qt6.so

.include <bsd.port.mk>
