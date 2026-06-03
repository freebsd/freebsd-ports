PORTNAME=	knitr
DISTVERSION=	1.51
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	General-Purpose Package for Dynamic Report Generation in R
WWW=		https://cran.r-project.org/package=knitr

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-evaluate>=0.15:devel/R-cran-evaluate \
		R-cran-highr>=0.11:textproc/R-cran-highr \
		R-cran-xfun>=0.52:misc/R-cran-xfun \
		R-cran-yaml>=2.1.19:textproc/R-cran-yaml
TEST_DEPENDS=	R-cran-bslib>0:www/R-cran-bslib \
		R-cran-DBI>=0.4.1:databases/R-cran-DBI \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-formatR>0:textproc/R-cran-formatR \
		R-cran-htmlwidgets>=0.7:www/R-cran-htmlwidgets \
		R-cran-jpeg>0:graphics/R-cran-jpeg \
		R-cran-litedown>0:textproc/R-cran-litedown \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-markdown>=1.3:textproc/R-cran-markdown \
		R-cran-png>0:graphics/R-cran-png \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-rgl>=0.95.1201:graphics/R-cran-rgl \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-sass>0:textproc/R-cran-sass \
		R-cran-testit>0:devel/R-cran-testit \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tinytex>=0.56:print/R-cran-tinytex \
		R-cran-webshot>0:www/R-cran-webshot

USES=		cran:auto-plist

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
