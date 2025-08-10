PORTNAME=	boringssl
PORTVERSION=	0.20250807.0
CATEGORIES=	security
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${PORTVERSION}_GH0.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL
WWW=		https://boringssl.googlesource.com/boringssl/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:no_targets,1.24 localbase perl5

CONFLICTS_INSTALL=	libressl libressl-devel openssl openssl111 \
			openssl3[12345] openssl-quictls openssl31-quictls

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
DISTFILES+=	filippo.io/edwards25519/@v/v1.1.0.zip:gomods \
		filippo.io/edwards25519/@v/v1.1.0.mod:gomods \
		golang.org/x/crypto/@v/v0.37.0.zip:gomods \
		golang.org/x/crypto/@v/v0.37.0.mod:gomods \
		golang.org/x/sys/@v/v0.32.0.zip:gomods \
		golang.org/x/sys/@v/v0.32.0.mod:gomods
.endif

post-install:
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0

.include <bsd.port.post.mk>
