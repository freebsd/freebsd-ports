PORTNAME=	httpx2
DISTVERSION=	2.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Next generation HTTP client
WWW=		https://github.com/pydantic/httpx2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.8.0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore2>=2.4.0:www/py-httpcore2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}truststore>=0.10:security/py-truststore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=		BROTLI CLI HTTP2 SOCKS ZSTD
OPTIONS_DEFAULT=	HTTP2 SOCKS

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR}
CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8<9:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>=2<3:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rich>=10<16:textproc/py-rich@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR}
ZSTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
