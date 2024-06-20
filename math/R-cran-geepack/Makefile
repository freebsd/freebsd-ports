PORTNAME=	geepack
DISTVERSION=	1.3.11
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generalized Estimating Equation Package
WWW=		https://cran.r-project.org/web/packages/geepack/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-broom>=0:devel/R-cran-broom \
		R-cran-magrittr>=0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
