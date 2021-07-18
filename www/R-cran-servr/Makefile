PORTNAME=	servr
PORTVERSION=	0.22
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple HTTP Server to Serve Static Files or Dynamic Documents

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-mime>=0.2:misc/R-cran-mime \
		R-cran-httpuv>=1.5.2:www/R-cran-httpuv \
		R-cran-xfun>0:misc/R-cran-xfun \
		R-cran-jsonlite>0:converters/R-cran-jsonlite
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
