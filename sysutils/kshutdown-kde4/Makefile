# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	3.0beta6
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/3.0%20Beta%206/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

USE_ZIP=	yes
USES=		cmake
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix workspace

LATEST_LINK=	${PORTNAME}-kde4

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
