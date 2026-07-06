PORTNAME=	boringssl
DISTVERSION=	0.20260616.0
PORTREVISION=	1
CATEGORIES=	security
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${DISTVERSION}_GH0.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL
WWW=		https://boringssl.googlesource.com/boringssl/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:1.25,no_targets localbase perl5

CONFLICTS_INSTALL=	aws-lc libressl libressl-devel openssl openssl[34][0456]

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	google
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1

CFLAGS_i386=	-msse2
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
TEST_TARGET=	run_tests
MAKE_ENV+=	GOFLAGS=-mod=readonly \
		GOPROXY=file://${DISTDIR}

.include <bsd.port.pre.mk>

.if ${.TARGETS} == "makesum" || ${.TARGETS} == "test"
MASTER_SITES+=	https://proxy.golang.org/:gomods
DISTFILES+=	filippo.io/edwards25519/@v/v1.2.0.zip:gomods \
		filippo.io/edwards25519/@v/v1.2.0.mod:gomods \
		filippo.io/mldsa/@v/v0.0.0-20260215214346-43d0283efc3e.zip:gomods \
		filippo.io/mldsa/@v/v0.0.0-20260215214346-43d0283efc3e.mod:gomods \
		golang.org/x/crypto/@v/v0.52.0.zip:gomods \
		golang.org/x/crypto/@v/v0.52.0.mod:gomods \
		golang.org/x/sys/@v/v0.45.0.zip:gomods \
		golang.org/x/sys/@v/v0.45.0.mod:gomods
.endif

post-install:
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0

.include <bsd.port.post.mk>
