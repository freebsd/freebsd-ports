# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.9.7
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Toolkit for Encryption, Signatures and Certificates Based on OpenSSL

LICENSE=	MIT

TEST_DEPENDS=	bash:shells/bash

USES=		cran:auto-plist,compiles shebangfix ssl

SHEBANG_FILES=	${WRKSRC}/tests/google.dk/generate.bash

R_POSTCMD_INSTALL_OPTIONS+=	--configure-vars="INCLUDE_DIR=${OPENSSLINC} LIB_DIR=${OPENSSLLIB}"

post-patch:
	${REINPLACE_CMD} -e '1,5d' ${WRKSRC}/src/ssl.c

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	detected LibreSSL (missing RSA_get0_key and others)
.endif

.include <bsd.port.post.mk>
