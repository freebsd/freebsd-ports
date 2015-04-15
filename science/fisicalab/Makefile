# $FreeBSD$

PORTNAME=	fisicalab
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	science gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	fisicalab

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Physics simulation program for educational use

LICENSE=	GPLv3

LIB_DEPENDS+=	libgsl.so:${PORTSDIR}/math/gsl

USES=		gnustep
GNU_CONFIGURE=	yes
USE_GNUSTEP=	build gui

.include <bsd.port.mk>
