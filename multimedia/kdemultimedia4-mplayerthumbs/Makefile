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

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USES=		cmake:outsource
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
