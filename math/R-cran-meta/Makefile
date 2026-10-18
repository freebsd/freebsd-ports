PORTNAME=	meta
DISTVERSION=	8.5-0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	General package for meta-analysis
WWW=		https://cran.r-project.org/package=meta

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-CompQuadForm>0:math/R-cran-CompQuadForm \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-lme4>0:math/R-cran-lme4 \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-metabook>=0.2.0:math/R-cran-metabook \
		R-cran-metafor>=3.0.0:math/R-cran-metafor \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-readr>0:textproc/R-cran-readr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-scales>0:graphics/R-cran-scales \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist

.include <bsd.port.mk>
