PORTNAME=	ddalpha
PORTVERSION=	1.3.15
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Depth-Based Classification and Calculation of Data Depth
WWW=		https://cran.r-project.org/web/packages/ddalpha/

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-BH>0:devel/R-cran-BH \
		R-cran-geometry>0:math/R-cran-geometry \
		R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-robustbase>0:math/R-cran-robustbase \
		R-cran-sfsmisc>0:devel/R-cran-sfsmisc

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
