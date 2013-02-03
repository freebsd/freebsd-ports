# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		mplayerthumbs
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		multimedia kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=		kdemultimedia-
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		MPlayer-based thumbnail generator for video files

LICENSE=		LGPL21

RUN_DEPENDS=		mplayer:${PORTSDIR}/multimedia/mplayer

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		phonon moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

.include <bsd.port.mk>
