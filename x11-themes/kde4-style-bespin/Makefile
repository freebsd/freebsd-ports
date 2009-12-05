# New ports collection makefile for:   bespin
# Date created:                        Thu Dec  3 04:21:05  EST 2009
# Whom:                                Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	bespin
PORTVERSION=	200912030441
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://meatwad.mouf.net/~steve/
PKGNAMEPREFIX=	kde4-style-

MAINTAINER=	steve@mouf.net
COMMENT=	A configurable KDE style

WRKSRC=		${WRKDIR}/cloudcity
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

.include <bsd.port.mk>
