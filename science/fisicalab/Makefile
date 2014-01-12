# $FreeBSD$

PORTNAME=	fisicalab
PORTVERSION=	0.3.3
CATEGORIES=	science gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	fisicalab

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Physics simulation program for educational use

LICENSE=	GPLv3

LIB_DEPENDS+=	libgsl.so:${PORTSDIR}/math/gsl

USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

.include <bsd.port.mk>
