# New ports collection makefile for:   bespin
# Date created:                        Thu Dec  3 04:21:05  EST 2009
# Whom:                                Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	bespin
PORTVERSION=	201303202227
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://bsd.e-shell.net/local/
DISTFILES=	cloudcity-${PORTVERSION}.tar.gz
PKGNAMEPREFIX=	kde4-style-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A configurable KDE style

WRKSRC=		${WRKDIR}/cloudcity
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
