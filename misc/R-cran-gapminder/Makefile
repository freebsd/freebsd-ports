PORTNAME=	gapminder
DISTVERSION=	1.0.1
CATEGORIES=	misc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Data from Gapminder
WWW=		https://cran.r-project.org/package=gapminder

LICENSE=	CC0-1.0

RUN_DEPENDS=	R-cran-tibble>0:devel/R-cran-tibble
TEST_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-ggplot2>=3.0.0:graphics/R-cran-ggplot2 \
		R-cran-knitr>=1.47:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat

USES=		cran:auto-plist

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
