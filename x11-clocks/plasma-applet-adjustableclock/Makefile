# New ports collection makefile for:	plasma-applet-adjustableclock
# Date Created:				2011-02-23
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	adjustableclock
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	x11-clocks deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	92825-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Highly configurable clock plasmoid for KDE4

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		cmake gettext
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
