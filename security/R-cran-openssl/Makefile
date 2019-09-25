# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.4.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Toolkit for Encryption, Signatures and Certificates Based on OpenSSL

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	bash:shells/bash

USES=		cran:auto-plist,compiles shebangfix ssl

SHEBANG_FILES=	${WRKSRC}/tests/google.dk/generate.bash

.include <bsd.port.mk>
