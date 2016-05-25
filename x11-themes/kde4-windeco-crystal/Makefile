# Created by: decept
# $FreeBSD$

PORTNAME=	crystal
PORTVERSION=	2.2.1
PORTREVISION=	4
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-windeco-
DISTNAME=	75140-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Transparent KDE window decoration

LICENSE=	GPLv2

USE_KDE4=	kdelibs automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		corelib gui qt3support
USES=		cmake:outsource tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
