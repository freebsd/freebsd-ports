PORTNAME=	rvest
PORTVERSION=	1.0.5
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages
WWW=		https://cran.r-project.org/web/packages/rvest/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-httr>=0.5:www/R-cran-httr \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-selectr>0:www/R-cran-selectr \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-xml2>=1.4.0:textproc/R-cran-xml2

USES=		cran:auto-plist

.include <bsd.port.mk>
