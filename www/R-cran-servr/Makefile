PORTNAME=	servr
PORTVERSION=	0.28
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple HTTP Server to Serve Static Files or Dynamic Documents
WWW=		https://cran.r-project.org/web/packages/servr/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-httpuv>=1.5.2:www/R-cran-httpuv \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-mime>=0.2:misc/R-cran-mime \
		R-cran-xfun>0:misc/R-cran-xfun

USES=		cran:auto-plist

.include <bsd.port.mk>
