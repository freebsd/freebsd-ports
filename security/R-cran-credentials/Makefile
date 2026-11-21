PORTNAME=	credentials
DISTVERSION=	2.0.3
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Tools for Managing SSH and Git Credentials
WWW=		https://docs.ropensci.org/credentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-openssl>=1.3:security/R-cran-openssl \
		R-cran-sys>=2.1:devel/R-cran-sys
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist

.include <bsd.port.mk>
