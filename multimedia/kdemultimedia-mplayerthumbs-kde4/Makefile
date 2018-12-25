# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mplayerthumbs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	multimedia kde kde-kde4
PKGNAMEPREFIX=	kdemultimedia-
PKGNAMESUFIFX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	MPlayer-based thumbnail generator for video files

LICENSE=	LGPL21

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		phonon moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
