PORTNAME=	spdep
DISTVERSION=	1.4-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Spatial dependence: weighting schemes, statistics, and models
WWW=		https://cran.r-project.org/web/packages/spdep/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-deldir>0:math/R-cran-deldir \
		R-cran-e1071>0:science/R-cran-e1071 \
		R-cran-s2>0:graphics/R-cran-s2 \
		R-cran-sf>0:math/R-cran-sf \
		R-cran-sp>=1.0:math/R-cran-sp \
		R-cran-spData>=2.3.1:math/R-cran-spData \
		R-cran-units>0:math/R-cran-units

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
