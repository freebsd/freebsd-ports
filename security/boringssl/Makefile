PORTNAME=	boringssl
PORTVERSION=	0.0.0.0.2023.04.11.01
CATEGORIES=	security

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL
WWW=		https://boringssl.googlesource.com/boringssl/

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:no_targets localbase perl5

CONFLICTS_INSTALL=	libressl libressl-devel \
			openssl openssl3[01] openssl-quictls

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	89de6e1
GH_TUPLE=	golang:crypto:v0.6.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.7.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.5.0:golang_term/vendor/golang.org/x/term
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1 \
		-DCMAKE_BUILD_TYPE=Release
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
TEST_TARGET=	run_tests
MAKE_ENV+=	GOFLAGS=-mod=mod \
		GOPATH=${WRKSRC}/vendor \
		GOPROXY=off

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tool/bssl ${STAGEDIR}${PREFIX}/bin/
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include)
	${INSTALL_LIB} ${WRKSRC}/crypto/libcrypto.so ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${INSTALL_LIB} ${WRKSRC}/ssl/libssl.so ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so
	${LN} -sf libcrypto.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so
	${LN} -sf libssl.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libssl.so.1

.include <bsd.port.mk>
