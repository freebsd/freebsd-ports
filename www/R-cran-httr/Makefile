PORTNAME=	httr
PORTVERSION=	1.4.8
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Working with URLs and HTTP
WWW=		https://cran.r-project.org/web/packages/httr/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-curl>=5.1.0:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-openssl>=0.8:security/R-cran-openssl \
		R-cran-R6>0:devel/R-cran-R6

USES=		cran:auto-plist

.include <bsd.port.mk>
