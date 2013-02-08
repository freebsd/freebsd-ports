# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		ffmpegthumbs
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		multimedia kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=		kdemultimedia-
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		ffmpeg-based thumbnail creator for video files

LICENSE=		GPLv2

LIB_DEPENDS=		swscale.1:${PORTSDIR}/multimedia/ffmpeg

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

.include <bsd.port.mk>
