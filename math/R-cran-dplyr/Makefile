PORTNAME=	dplyr
DISTVERSION=	1.2.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Grammar of Data Manipulation
WWW=		https://github.com/hadley/dplyr

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-assertthat>=0.2.0:math/R-cran-assertthat \
		R-cran-generics>=0:devel/R-cran-generics \
		R-cran-glue>=1.3.2:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.5:devel/R-cran-lifecycle \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-pillar>=1.9.0:devel/R-cran-pillar \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>=1.1.7:devel/R-cran-rlang \
		R-cran-tibble>=3.2.0:devel/R-cran-tibble \
		R-cran-tidyselect>=1.2.0:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.7.1:devel/R-cran-vctrs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
