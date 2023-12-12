PORTNAME=	DT
PORTVERSION=	0.31
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Wrapper of the JavaScript Library 'DataTables'
WWW=		https://cran.r-project.org/web/packages/DT/

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-crosstalk>0:www/R-cran-crosstalk \
		R-cran-htmltools>=0.3.6:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>=1.3:www/R-cran-htmlwidgets \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-jquerylib>0:www/R-cran-jquerylib \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-promises>0:devel/R-cran-promises

USES=		cran:auto-plist

.include <bsd.port.mk>
