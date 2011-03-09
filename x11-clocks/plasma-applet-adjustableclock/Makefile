# New ports collection makefile for:	plasma-applet-adjustableclock
# Date Created:				2011-02-23
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	adjustableclock
PORTVERSION=	2.6.1
CATEGORIES=	x11-clocks deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	92825-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Highly configurable clock plasmoid for KDE4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CMAKE_ARGS=	-Wno-dev

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
