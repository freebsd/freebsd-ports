PORTNAME=	webutils
DISTVERSION=	1.2.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Parses http request data
WWW=		https://cran.r-project.org/package=webutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-curl>=2.5:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
