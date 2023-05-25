PORTNAME=	pkcs11-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
CATEGORIES=	security

MAINTAINER=	eric.devolder@gmail.com
COMMENT=	Tools for managing PKCS11 cryptographic tokens
WWW=		https://github.com/Mastercard/pkcs11-tools

LICENSE=	APACHE20

BROKEN_SSL=	libressl openssl30 openssl31
BROKEN_SSL_REASON_libressl=	error: use of undeclared identifier 'EVP_PKEY_X25519' (LibreSSL has no support for Edwards curves)
BROKEN_SSL_REASON_openssl30=	error: undefined symbol: EVP_PKEY_*
BROKEN_SSL_REASON_openssl31=	error: undefined symbol: EVP_PKEY_*

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		flex:textproc/flex
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf:build bison compiler:c11 libtool:build pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Mastercard
GH_TUPLE=	coreutils:gnulib:3148eb10e:gnulib \
		oasis-tcs:pkcs11:a136aac:oasis_pkcs11

GNU_CONFIGURE=	yes

MAKE_ENV=	LIBCRYPTO_RPATH=${OPENSSLBASE}/lib

INSTALL_TARGET=	install-strip

# workaround for Bug#255277:
# -lcrypto # fails to find symbol in the shared library: ld: error: undefined symbol: EVP_PKEY_meth_get_digestsign
LDFLAGS+=	${OPENSSLBASE}/lib/libcrypto.a

post-extract:
	@${RMDIR} ${WRKSRC}/.gnulib ${WRKSRC}/include/oasis-pkcs11
	@${MV} ${WRKSRC_gnulib} ${WRKSRC}/.gnulib
	@${MV} ${WRKSRC_oasis_pkcs11} ${WRKSRC}/include/oasis-pkcs11

pre-configure:
	@cd ${WRKSRC} && BUILD_PORT=1 ${WRKSRC}/bootstrap.sh

.include <bsd.port.mk>
