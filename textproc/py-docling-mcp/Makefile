PORTNAME=	docling-mcp
DISTVERSION=	3.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Running Docling as an agent using tools
WWW=		https://github.com/docling-project/docling-mcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-core>=2.51.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-slim>=2.92.0:textproc/py-docling-slim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=2.0.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.4:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.1.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.19.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
