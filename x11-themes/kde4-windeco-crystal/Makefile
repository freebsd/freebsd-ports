# Created by: decept
# $FreeBSD$

PORTNAME=	crystal
PORTVERSION=	2.2.1
PORTREVISION=	6
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-windeco-
DISTNAME=	75140-${PORTNAME}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Transparent KDE window decoration

LICENSE=	GPLv2

USES=		cmake:outsource,noninja kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		corelib gui qt3support
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
