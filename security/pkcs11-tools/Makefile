PORTNAME=	pkcs11-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	security

MAINTAINER=	eric.devolder@gmail.com
COMMENT=	Tools for managing PKCS11 cryptographic tokens
WWW=		https://github.com/Mastercard/pkcs11-tools

LICENSE=	APACHE20 THIRDPARTY
LICENSE_COMB=	multi
LICENSE_NAME_THIRDPARTY=	Third-party licenses
LICENSE_FILE_THIRDPARTY=	${WRKSRC}/docs/TPLICENSES.md
LICENSE_PERMS_THIRDPARTY=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_SSL=	libressl openssl openssl31
BROKEN_SSL_REASON_libressl=	error: use of undeclared identifier 'EVP_PKEY_X25519' (LibreSSL has no support for Edwards curves)
BROKEN_SSL_REASON_openssl=	error: undefined symbol: EVP_PKEY_*
BROKEN_SSL_REASON_openssl31=	error: undefined symbol: EVP_PKEY_*

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		flex:textproc/flex
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf:build bison compiler:c11 libtool:build pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Mastercard
GH_TUPLE=	coreutils:gnulib:d1b40e0:gnulib \
		oasis-tcs:pkcs11:a136aac:oasis_pkcs11

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

GNU_CONFIGURE=	yes

MAKE_ENV=	LIBCRYPTO_RPATH=${OPENSSLBASE}/lib

INSTALL_TARGET=	install-strip

post-extract:
	@${RMDIR} ${WRKSRC}/.gnulib ${WRKSRC}/include/oasis-pkcs11
	@${MV} ${WRKSRC_gnulib} ${WRKSRC}/.gnulib
	@${MV} ${WRKSRC_oasis_pkcs11} ${WRKSRC}/include/oasis-pkcs11

pre-configure:
	@cd ${WRKSRC} && BUILD_PORT=1 ${WRKSRC}/bootstrap.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/README.md \
		${WRKSRC}/docs/INSTALL.md \
		${WRKSRC}/docs/MANUAL.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
