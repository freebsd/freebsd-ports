# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mplayerthumbs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdemultimedia-
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	MPlayer-based thumbnail generator for video files

LICENSE=	LGPL21

RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake:outsource tar:xz
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
