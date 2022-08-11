PORTNAME=	shiny
PORTVERSION=	1.7.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-httpuv>=1.5.2:www/R-cran-httpuv \
		R-cran-mime>=0.3:misc/R-cran-mime \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-xtable>0:textproc/R-cran-xtable \
		R-cran-fontawesome>=0.2.1:devel/R-cran-fontawesome \
		R-cran-htmltools>=0.5.2:textproc/R-cran-htmltools \
		R-cran-R6>=2.0:devel/R-cran-R6 \
		R-cran-sourcetools>0:devel/R-cran-sourcetools \
		R-cran-later>=1.0.0:devel/R-cran-later \
		R-cran-promises>=1.1.0:devel/R-cran-promises \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-fastmap>=1.1.0:databases/R-cran-fastmap \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-commonmark>=1.7:textproc/R-cran-commonmark \
		R-cran-glue>=1.3.2:devel/R-cran-glue \
		R-cran-bslib>=0.3.0:www/R-cran-bslib \
		R-cran-cachem>0:databases/R-cran-cachem \
		R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-lifecycle>=0.2.0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
