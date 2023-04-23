PORTNAME=	hunspell
DISTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	High-Performance Stemmer, Tokenizer, and Spell Checker
WWW=		https://docs.ropensci.org/hunspell/

LICENSE=	GPLv2 LGPL21 MPL11
LICENSE_COMB=	dual

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-digest>0:security/R-cran-digest
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
