PORTNAME=	gh
DISTVERSION=	1.5.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	GitHub API
WWW=		https://gh.r-lib.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>=3.0.1:devel/R-cran-cli \
		R-cran-gitcreds>0:security/R-cran-gitcreds \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-httr2>=1.0.6:www/R-cran-httr2 \
		R-cran-ini>0:devel/R-cran-ini \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
