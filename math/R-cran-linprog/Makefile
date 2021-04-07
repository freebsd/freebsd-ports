PORTNAME=	linprog
DISTVERSION=	0.9-2
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Linear Programming / Optimization

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-lpSolve>0:math/R-cran-lpSolve
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
