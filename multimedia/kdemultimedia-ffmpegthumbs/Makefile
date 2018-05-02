# $FreeBSD$

PORTNAME=	ffmpegthumbs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-applications
PKGNAMEPREFIX=	kdemultimedia-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FFmpeg-based thumbnail generator for video files

LICENSE=	GPLv2

LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg

USES=		cmake:outsource kde:5 pkgconfig tar:xz
USE_KDE=	completion config coreaddons jobwidgets kio service widgetsaddons
USE_QT5=	core gui network widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
