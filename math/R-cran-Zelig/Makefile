# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Zelig
DISTVERSION=	4.1-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Everyone's Statistical Software

BUILD_DEPENDS=	R-cran-sandwich>=0:${PORTSDIR}/math/R-cran-sandwich
RUN_DEPENDS=	R-cran-sandwich>=0:${PORTSDIR}/math/R-cran-sandwich

USE_R_MOD=	yes
R_MOD_AUTOPLIST=yes

.include <bsd.port.mk>
