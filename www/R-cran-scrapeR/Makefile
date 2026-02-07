PORTNAME=	scrapeR
PORTVERSION=	0.1.8
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Scraping Data from HTML and XML Documents
WWW=		https://cran.r-project.org/web/packages/scrapeR/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-httr>0:www/R-cran-httr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rvest>0:www/R-cran-rvest \
		R-cran-stringr>0:textproc/R-cran-stringr

USES=		cran:auto-plist

.include <bsd.port.mk>
