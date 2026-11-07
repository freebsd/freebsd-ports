PORTNAME=	immichpy
DISTVERSION=	9.2.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Typed Python API layer for Immich automation and integrations
WWW=		https://github.com/timonrieger/immichpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.13:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.4<4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-retry>=2.8.3<3:www/py-aiohttp-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2<3.1:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2024.11.6:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.8<16:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtoml>=0.13<1:textproc/py-rtoml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9<10:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.27.2<1:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2<5:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's|uv_build *[=<>!~,0-9.]+|uv_build|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
