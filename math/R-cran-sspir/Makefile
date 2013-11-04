# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sspir
PORTVERSION=	0.2.10
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	A glm-like formula to define dynamic generalized linear models

RUN_DEPENDS=	R-cran-mvtnorm>=0.9.96_11:${PORTSDIR}/math/R-cran-mvtnorm \
		R-cran-KFAS>=0.9.11_3:${PORTSDIR}/math/R-cran-KFAS

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
