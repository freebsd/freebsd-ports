# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	3.2
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

USES=		alias cmake:outsource compiler:c++0x gettext zip
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 workspace

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
