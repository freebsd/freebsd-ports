# New ports collection makefile for:	kshutdown
# Date created:				Mon Jan  9 18:06:42 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	2.0beta11
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/2.0%20Beta%2011/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

USE_ZIP=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix workspace

MAKE_JOBS_SAFE=	yes
LATEST_LINK=	${PORTNAME}-kde4

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
