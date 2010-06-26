# New ports collection makefile for:   nitrogen
# Date created:                        29th October, 2009
# Whom:                                kmoore
#
# $FreeBSD$
#

PORTNAME=	nitrogen
PORTVERSION=	3.3.3
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-windeco-
DISTNAME=	99551-${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	kmoore@freebsd.org
COMMENT=	KDE4 window decoration

USE_GZIP=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-Source

.include <bsd.port.mk>
