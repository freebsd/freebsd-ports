PORTNAME=	readxl
DISTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read Excel Files

LICENSE=	GPLv3

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-progress>0:devel/R-cran-progress
RUN_DEPENDS=	R-cran-Rcpp>=0.12.18:devel/R-cran-Rcpp \
		R-cran-tibble>=1.3.1:devel/R-cran-tibble \
		R-cran-cellranger>0:textproc/R-cran-cellranger \
		R-cran-progress>0:devel/R-cran-progress
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-rprojroot>=1.1:devel/R-cran-rprojroot \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
