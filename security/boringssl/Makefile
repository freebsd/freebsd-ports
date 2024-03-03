PORTNAME=	boringssl
PORTVERSION=	0.0.0.0.2024.02.28.01
CATEGORIES=	security
MASTER_SITES+=	https://proxy.golang.org/:gomods
DISTFILES+=	golang.org/x/crypto/@v/v0.17.0.zip:gomods \
		golang.org/x/crypto/@v/v0.17.0.mod:gomods \
		golang.org/x/net/@v/v0.17.0.zip:gomods \
		golang.org/x/net/@v/v0.17.0.mod:gomods \
		golang.org/x/sys/@v/v0.15.0.zip:gomods \
		golang.org/x/sys/@v/v0.15.0.mod:gomods \
		golang.org/x/term/@v/v0.15.0.zip:gomods \
		golang.org/x/term/@v/v0.15.0.mod:gomods
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${PORTVERSION}-${GH_TAGNAME}_GH0.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fork of OpenSSL
WWW=		https://boringssl.googlesource.com/boringssl/

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource cpe go:no_targets localbase perl5

CONFLICTS_INSTALL=	libressl libressl-devel \
			openssl openssl3[012] openssl-quictls

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	df3b58e
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1

CFLAGS_i386=	-msse2
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
TEST_TARGET=	run_tests
MAKE_ENV+=	GOFLAGS=-mod=readonly \
		GOPROXY=file://${DISTDIR}

post-install:
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0

.include <bsd.port.mk>
