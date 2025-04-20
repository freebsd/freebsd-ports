PORTNAME=	etm
DISTVERSION=	1.1.2
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Empirical Transition Matrix
WWW=		https://cran.r-project.org/web/packages/etm/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-Rcpp>=0.11.4:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>0:math/R-cran-RcppArmadillo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
