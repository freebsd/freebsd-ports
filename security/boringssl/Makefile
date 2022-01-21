PORTNAME=	boringssl
PORTVERSION=	0.0.0.0.2022.01.19.01
CATEGORIES=	security

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:no_targets localbase perl5

CONFLICTS_INSTALL=	security/libressl \
			security/libressl-devel \
			security/openssl \
			security/openssl-devel \
			security/openssl-quictls

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	be04c56
GH_TUPLE=	golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:04defd469f4e:golang_net/vendor/golang.org/x/net \
		golang:sys:04245dca01da:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1 \
		-DCMAKE_BUILD_TYPE=Release
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
TEST_TARGET=	run_tests
GO_BUILDFLAGS+=	-mod=vendor
MAKE_ENV+=	GOPATH=${WRKSRC}/vendor GOPROXY=off

post-patch:
	@${GREP} -FRl -- '-D_XOPEN_SOURCE=700' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's,-D_XOPEN_SOURCE=700,,'
	@${GREP} -FRl '${GO_EXECUTABLE} run ' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -r -e 's,([$][{]GO_EXECUTABLE[}] run),\1 ${GO_BUILDFLAGS},'
	@${FIND} ${WRKSRC}/include -name '*.bak' -delete

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
