PORTNAME=	httpuv
DISTVERSION=	1.6.14
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

PATCH_SITES=	https://github.com/rstudio/httpuv/pull/396/commits/
PATCHFILES=	fe516bc16655e338bce8078c35d618732ab3e40a.patch:-p1

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
LIB_DEPENDS=	libuv.so:devel/libuv
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-testthat>0:devel/R-cran-testthat
# 1 test failing: https://github.com/rstudio/httpuv/issues/393

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
