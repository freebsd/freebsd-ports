PORTNAME=	bslib
PORTVERSION=	0.5.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Custom 'Bootstrap' 'Sass' Themes for 'shiny' and 'rmarkdown'
WWW=		https://cran.r-project.org/web/packages/bslib/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-cachem>0:databases/R-cran-cachem \
		R-cran-htmltools>=0.5.4:textproc/R-cran-htmltools \
		R-cran-jquerylib>=0.1.3:www/R-cran-jquerylib \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-memoise>=2.0.1:devel/R-cran-memoise \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-sass>=0.4.0:textproc/R-cran-sass
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
