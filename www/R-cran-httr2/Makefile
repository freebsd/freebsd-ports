PORTNAME=	httr2
DISTVERSION=	1.0.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Tools for Working HTTP requests
WWW=		https://cran.r-project.org/web/packages/httr2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-curl>=5.0.2:ftp/R-cran-curl \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
