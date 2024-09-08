PORTNAME=	openssl
DISTVERSION=	2.2.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Toolkit for Encryption, Signatures and Certificates Based on OpenSSL
WWW=		https://cran.r-project.org/web/packages/openssl/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass
BUILD_DEPENDS=	bash:shells/bash \
		${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-sodium>0:security/R-cran-sodium \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles shebangfix ssl

SHEBANG_FILES=	${WRKSRC}/tests/google.dk/generate.bash

.include <bsd.port.mk>
