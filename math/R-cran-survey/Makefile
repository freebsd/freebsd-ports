# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	survey
DISTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Analysis of complex survey samples

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-minqa>=1.1.15:math/R-cran-minqa \
		R-cran-numDeriv>=0:math/R-cran-numDeriv \
		R-cran-mitools>=2.4:math/R-cran-mitools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
