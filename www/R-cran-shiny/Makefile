PORTNAME=	shiny
PORTVERSION=	1.11.1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R
WWW=		https://shiny.posit.co/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-bslib>=0.6.0:www/R-cran-bslib \
		R-cran-cachem>=1.1.0:databases/R-cran-cachem \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-commonmark>=1.7:textproc/R-cran-commonmark \
		R-cran-fastmap>=1.1.1:databases/R-cran-fastmap \
		R-cran-fontawesome>=0.4.0:devel/R-cran-fontawesome \
		R-cran-glue>=1.3.2:devel/R-cran-glue \
		R-cran-htmltools>=0.5.4:textproc/R-cran-htmltools \
		R-cran-httpuv>=1.5.2:www/R-cran-httpuv \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-later>=1.0.0:devel/R-cran-later \
		R-cran-lifecycle>=0.2.0:devel/R-cran-lifecycle \
		R-cran-mime>=0.3:misc/R-cran-mime \
		R-cran-promises>=1.3.2:devel/R-cran-promises \
		R-cran-R6>=2.0:devel/R-cran-R6 \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-sourcetools>0:devel/R-cran-sourcetools \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xtable>0:textproc/R-cran-xtable

USES=		cran:auto-plist

.include <bsd.port.mk>
