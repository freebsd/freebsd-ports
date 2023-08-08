PORTNAME=	credentials
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Tools for Managing SSH and Git Credentials
WWW=		https://docs.ropensci.org/credentials

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-openssl>=1.3:security/R-cran-openssl \
		R-cran-sys>=2.1:devel/R-cran-sys \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-askpass>0:security/R-cran-askpass
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
