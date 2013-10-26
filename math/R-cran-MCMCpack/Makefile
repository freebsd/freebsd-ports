# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MCMCpack
DISTVERSION=	1.3-3
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Markov chain Monte Carlo Package

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-coda>0.11.3:${PORTSDIR}/math/R-cran-coda

# Actually required 4.0 or later, but at least 4.2 in the FreeBSD ports tree
USE_GCC=	4.2+
USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
