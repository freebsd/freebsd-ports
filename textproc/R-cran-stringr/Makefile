PORTNAME=	stringr
DISTVERSION=	1.5.2
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Make it easier to work with strings
WWW=		https://cran.r-project.org/web/packages/stringr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>=1.6.1:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-stringi>=1.5.3:textproc/R-cran-stringi \
		R-cran-vctrs>0:devel/R-cran-vctrs

USES=		cran:auto-plist

.include <bsd.port.mk>
