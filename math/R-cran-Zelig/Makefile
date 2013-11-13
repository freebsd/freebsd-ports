# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Zelig
DISTVERSION=	4.1-3
PORTREVISION=	3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Everyone's Statistical Software

BUILD_DEPENDS=	R-cran-sandwich>=0:${PORTSDIR}/math/R-cran-sandwich
RUN_DEPENDS=	R-cran-sandwich>=0:${PORTSDIR}/math/R-cran-sandwich

USE_R_MOD=	yes
R_MOD_AUTOPLIST=yes

NO_STAGE=	yes
.include <bsd.port.mk>
