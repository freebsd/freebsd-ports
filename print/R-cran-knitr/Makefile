PORTNAME=	knitr
DISTVERSION=	1.49
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	General-Purpose Package for Dynamic Report Generation in R
WWW=		https://cran.r-project.org/web/packages/knitr/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-evaluate>=0.15:devel/R-cran-evaluate \
		R-cran-highr>=0.11:textproc/R-cran-highr \
		R-cran-xfun>=0.48:misc/R-cran-xfun \
		R-cran-yaml>=2.1.19:textproc/R-cran-yaml
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-bslib>0:www/R-cran-bslib \
		R-cran-DBI>=0.4:databases/R-cran-DBI \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-formatR>0:textproc/R-cran-formatR \
		R-cran-htmlwidgets>=0.7:www/R-cran-htmlwidgets \
		R-cran-jpeg>0:graphics/R-cran-jpeg \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-markdown>=1.3:textproc/R-cran-markdown \
		R-cran-png>0:graphics/R-cran-png \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-sass>0:textproc/R-cran-sass \
		R-cran-testit>0:devel/R-cran-testit \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tinytex>=0.46:print/R-cran-tinytex \
		R-cran-webshot>0:www/R-cran-webshot
TESTING_UNSAFE=	Required some packages that are not available in ports tree

USES=		cran:auto-plist

.include <bsd.port.mk>
