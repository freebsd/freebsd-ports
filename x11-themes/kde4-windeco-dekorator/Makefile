# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	dekorator
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-windeco-
DISTNAME=	87921-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Transparent KDE4 window decoration

LICENSE=	GPLv2

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
