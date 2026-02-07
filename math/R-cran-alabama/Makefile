PORTNAME=	alabama
DISTVERSION=	2015.3-1
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Constrained Nonlinear Optimization
WWW=		https://cran.r-project.org/web/packages/alabama/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-numDeriv>0:math/R-cran-numDeriv
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
