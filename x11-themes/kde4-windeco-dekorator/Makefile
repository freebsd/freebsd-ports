# New ports collection makefile for:    kde4-windeco-dekorator
# Date created:         2009-01-03
# Whom:                 Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	dekorator
PORTVERSION=	0.4.0.2
PORTREVISION=	1
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-windeco-
DISTNAME=	87921-${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Transparent KDE4 window decoration

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/kde4-${PORTNAME}-0.3

.include <bsd.port.mk>
