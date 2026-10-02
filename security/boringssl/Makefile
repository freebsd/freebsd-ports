PORTNAME=	boringssl
DISTVERSION=	0.20260929.0
CATEGORIES=	security
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${DISTVERSION}_GH0.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL
WWW=		https://boringssl.googlesource.com/boringssl/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:no_targets,1.27 localbase perl5

CONFLICTS_INSTALL=	aws-lc libressl libressl-devel openssl openssl[34][0456]

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	google
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1

CFLAGS_i386=	-msse2
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
GO_VARS=	BINARY_ALIAS="go=go${GO_SUFFIX}"
TEST_TARGET=	run_tests
MAKE_ENV+=	GOFLAGS=-mod=readonly \
		GOPROXY=file://${DISTDIR}
TEST_ENV+=	GOFLAGS=-mod=readonly \
		GOPROXY=file://${DISTDIR}

.include <bsd.port.pre.mk>

.if ${.TARGETS} == "makesum" || ${.TARGETS} == "test"
MASTER_SITES+=	https://proxy.golang.org/:gomods
DISTFILES+=	filippo.io/edwards25519/@v/v1.2.0.zip:gomods \
		filippo.io/edwards25519/@v/v1.2.0.mod:gomods \
		github.com/hexops/gotextdiff/@v/v1.0.3.zip:gomods \
		github.com/hexops/gotextdiff/@v/v1.0.3.mod:gomods \
		golang.org/x/crypto/@v/v0.55.0.zip:gomods \
		golang.org/x/crypto/@v/v0.55.0.mod:gomods \
		golang.org/x/sys/@v/v0.47.0.zip:gomods \
		golang.org/x/sys/@v/v0.47.0.mod:gomods \
		golang.org/x/term/@v/v0.45.0.zip:gomods \
		golang.org/x/term/@v/v0.45.0.mod:gomods
.endif

post-install:
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0

.include <bsd.port.post.mk>
