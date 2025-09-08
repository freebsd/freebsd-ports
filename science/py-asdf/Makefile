PORTNAME=	asdf
PORTVERSION=	4.4.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python tools to handle ASDF files
WWW=		https://www.asdf-format.org/projects/asdf/en/latest/ \
		https://github.com/asdf-format/asdf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=60:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asdf-standard>=1.1.0:science/py-asdf-standard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asdf-transform-schemas>=0.3:science/py-asdf-transform-schemas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=22.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.6.2:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.8:devel/py-semantic-version@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=2022.8.2:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0.10:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=0:devel/py-pytest-doctestplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-remotedata>=0:devel/py-pytest-remotedata@${PY_FLAVOR}
# fsspec[http]
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

SHEBANG_FILES=	asdf/_jsonschema/json/bin/jsonschema_suite

OPTIONS_DEFINE=	ALL HTTP LZ4
OPTIONS_DEFAULT=ALL HTTP LZ4
ALL_IMPLIES=	HTTP LZ4
ALL_DESC=	All optional dependencies
HTTP_DESC=	HTTP support via fsspec
LZ4_DESC=	Lz4 compression algorithm support

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fsspec>=2022.8.2:filesystems/py-fsspec@${PY_FLAVOR}
LZ4_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lz4>=0.10:archivers/py-lz4@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.11.4:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
