# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mplayerthumbs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde kde-kde4
PKGNAMEPREFIX=	kdemultimedia-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	MPlayer-based thumbnail generator for video files

LICENSE=	LGPL21

RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
