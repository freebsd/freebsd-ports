# New ports collection makefile for:   bespin
# Date created:                        Thu Dec  3 04:21:05  EST 2009
# Whom:                                Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	bespin
PORTVERSION=	200912030441
PORTREVISION=	5
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://meatwad.mouf.net/~steve/
PKGNAMEPREFIX=	kde4-style-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A configurable KDE style

IGNORE=		does not build with KDE SC 4.8

WRKSRC=		${WRKDIR}/cloudcity
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake

.include <bsd.port.mk>
