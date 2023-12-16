PORTNAME=	httpuv
DISTVERSION=	1.6.13
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	HTTP and WebSocket server library for R
WWW=		https://cran.r-project.org/web/packages/httpuv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-later>=0.8.0:devel/R-cran-later \
		R-cran-promises>0:devel/R-cran-promises \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-Rcpp>=1.0.7:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-testthat>0:devel/R-cran-testthat
# 1 test failing

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
