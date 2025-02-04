PORTNAME=	jose
DISTVERSION=	1.2.1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Read and write JSON Web Keys
WWW=		https://cran.r-project.org/package=jose

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-openssl>=1.2.1:security/R-cran-openssl
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
