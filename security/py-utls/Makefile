PORTNAME=	utls
PORTVERSION=	2026.9.21
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/jawah/utls/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	utls-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Drop-in ssl stdlib library using BoringSSL with first-class fingerprint impersonation
WWW=		https://github.com/jawah/utls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}maturin>=1.7:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wassima>=1<3:security/py-wassima@${PY_FLAVOR}

USES=		cargo llvm:build python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
# BoringSSL ships no PowerPC assembly, so use the portable C implementations.
CFLAGS_powerpc64le=	-DOPENSSL_NO_ASM
CXXFLAGS_powerpc64le=	-DOPENSSL_NO_ASM

USE_GITHUB=	nodefault
GH_TUPLE=	google:boringssl:7c1efd8:google_boringssl # https://github.com/cloudflare/boring/tree/553d389cf309fdea5075e8fa2d2f731be67d96cc/boring-sys/deps

post-patch:
	@${RMDIR} ${WRKDIR}/boring-553d389cf309fdea5075e8fa2d2f731be67d96cc/boring-sys/deps/boringssl/
	@${LN} -s ${WRKDIR}/boringssl-7c1efd8 ${WRKDIR}/boring-553d389cf309fdea5075e8fa2d2f731be67d96cc/boring-sys/deps/boringssl

.include <bsd.port.mk>
