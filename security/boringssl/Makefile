PORTNAME=	boringssl
PORTVERSION=	0.0.0.0.2023.06.20.01
CATEGORIES=	security
MASTER_SITES+=	https://proxy.golang.org/:gomods
DISTFILES+=	golang.org/x/crypto/@v/v0.6.0.zip:gomods \
		golang.org/x/crypto/@v/v0.6.0.mod:gomods \
		golang.org/x/net/@v/v0.7.0.zip:gomods \
		golang.org/x/net/@v/v0.7.0.mod:gomods \
		golang.org/x/sys/@v/v0.5.0.zip:gomods \
		golang.org/x/sys/@v/v0.5.0.mod:gomods \
		golang.org/x/term/@v/v0.5.0.zip:gomods \
		golang.org/x/term/@v/v0.5.0.mod:gomods
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${PORTVERSION}-${GH_TAGNAME}_GH0.tar.gz

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
GH_TAGNAME=	9c30e53
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1 \
		-DCMAKE_BUILD_TYPE=Release
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
TEST_TARGET=	run_tests
MAKE_ENV+=	GOFLAGS=-mod=readonly \
		GOPROXY=file://${DISTDIR}

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
