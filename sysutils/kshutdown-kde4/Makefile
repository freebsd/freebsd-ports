# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	3.0beta6
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/3.0%20Beta%206/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

USES=		cmake zip
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix workspace

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
