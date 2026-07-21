PORTNAME=	utls
PORTVERSION=	2026.7.8
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
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

USE_GITHUB=	nodefault
GH_TUPLE=	google:boringssl:e2a57cf:google_boringssl # https://github.com/cloudflare/boring/tree/931385ed41df448c82d150219f69af56e3c8399f/boring-sys/deps

post-patch:
	@${RMDIR} ${WRKDIR}/boring-931385ed41df448c82d150219f69af56e3c8399f/boring-sys/deps/boringssl/
	@${LN} -s ${WRKDIR}/boringssl-e2a57cf ${WRKDIR}/boring-931385ed41df448c82d150219f69af56e3c8399f/boring-sys/deps/boringssl

.include <bsd.port.mk>
