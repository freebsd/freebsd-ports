PORTNAME=	yardstick
DISTVERSION=	1.5.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tidy Characterizations of Model Performance
WWW=		https://yardstick.tidymodels.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-dplyr>=1.1.0:math/R-cran-dplyr \
		R-cran-generics>=0.1.2:devel/R-cran-generics \
		R-cran-hardhat>=1.4.3:devel/R-cran-hardhat \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-rlang>=1.1.4:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyselect>=1.2.0:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.5.0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
