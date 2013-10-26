# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	bespin
PORTVERSION=	201303202227
PORTREVISION=	1
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

NO_STAGE=	yes
.include <bsd.port.mk>
