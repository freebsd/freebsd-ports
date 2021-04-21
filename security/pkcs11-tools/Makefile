PORTNAME=	pkcs11-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	security

MAINTAINER=	eric.devolder@gmail.com
COMMENT=	Tools for managing PKCS11 cryptographic tokens

LICENSE=	APACHE20

BROKEN_SSL=			libressl
BROKEN_SSL_REASON_libressl=	error: use of undeclared identifier 'EVP_PKEY_X25519' (LibreSSL has no support for Edwards curves)

BUILD_DEPENDS=	autoconf>0:devel/autoconf \
		autoconf-archive>0:devel/autoconf-archive \
		automake>0:devel/automake \
		flex:textproc/flex
RUN_DEPENDS=	bash:shells/bash

USES=		bison compiler:c11 libtool:build pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Mastercard
GH_TUPLE=	coreutils:gnulib:5b3a6f94f:gnulib \
		oasis-tcs:pkcs11:df530bf:oasis_pkcs11

GNU_CONFIGURE=	yes

MAKE_ENV=	LIBCRYPTO_RPATH=${OPENSSLBASE}/lib

# workaround for Bug#255277:
LDFLAGS+=	${OPENSSLBASE}/lib/libcrypto.a # -lcrypto # fails to find symbol in the shared library: ld: error: undefined symbol: EVP_PKEY_meth_get_digestsign

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == base && ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085
BROKEN=	OpenSSL version is too old, lacks symbols: error: use of undeclared identifier 'EVP_PKEY_X25519', etc.
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/.gnulib ${WRKSRC}/include/oasis-pkcs11
	@${MV} ${WRKSRC_gnulib} ${WRKSRC}/.gnulib
	@${MV} ${WRKSRC_oasis_pkcs11} ${WRKSRC}/include/oasis-pkcs11

pre-configure:
	@cd ${WRKSRC} && BUILD_PORT=1 ${WRKSRC}/bootstrap.sh

.include <bsd.port.mk>
