PORTNAME=	stringr
PORTVERSION=	1.5.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Make it easier to work with strings
WWW=		https://cran.r-project.org/web/packages/stringr/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>=1.6.1:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-stringi>=1.5.3:textproc/R-cran-stringi \
		R-cran-vctrs>0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
