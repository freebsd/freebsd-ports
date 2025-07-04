PORTNAME=	psych
DISTVERSION=	2.5.6
CATEGORIES=	math science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Psych package for the R project
WWW=		https://cran.r-project.org/package=psych

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-GPArotation>0:math/R-cran-GPArotation \
		R-cran-mnormt>0:math/R-cran-mnormt
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-lme4>0:math/R-cran-lme4 \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
