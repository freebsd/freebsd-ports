PORTNAME=	bslib
PORTVERSION=	0.2.5.1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Custom 'Bootstrap' 'Sass' Themes for 'shiny' and 'rmarkdown'

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-htmltools>=0.5.1:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-sass>=0.4.0:textproc/R-cran-sass \
		R-cran-jquerylib>=0.1.3:www/R-cran-jquerylib \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
