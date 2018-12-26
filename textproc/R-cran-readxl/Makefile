# $FreeBSD$

PORTNAME=	readxl
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Read Excel Files

LICENSE=	GPLv3 BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.note

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-Rcpp>=0.12.12:devel/R-cran-Rcpp \
		R-cran-tibble>=1.1:devel/R-cran-tibble \
		R-cran-cellranger>0:textproc/R-cran-cellranger
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-rprojroot>=1.1:devel/R-cran-rprojroot \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
