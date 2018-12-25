# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpegthumbs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	multimedia kde kde-kde4
PKGNAMEPREFIX=	kdemultimedia-
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FFmpeg-based thumbnail generator for video files

LICENSE=	GPLv2

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg

USES=		cmake kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		moc_build qmake_build rcc_build uic_build \
		corelib dbus gui network svg xml

.include <bsd.port.mk>
