PORTNAME=	gtable
PORTVERSION=	0.3.4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Arrange grobs in tables
WWW=		https://cran.r-project.org/web/packages/gtable/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
