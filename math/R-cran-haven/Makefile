# $FreeBSD$

PORTNAME=	haven
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Import and Export 'SPSS', 'Stata' and 'SAS' Files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-Rcpp>=0.11.4:devel/R-cran-Rcpp \
		R-cran-hms>0:devel/R-cran-hms \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-forcats>=0.2.0:math/R-cran-forcats \
		R-cran-readr>=0.1.0:textproc/R-cran-readr \
		R-cran-tidyselect>=0:devel/R-cran-tidyselect
TEST_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-pillar>=1.1.1:devel/R-cran-pillar \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
