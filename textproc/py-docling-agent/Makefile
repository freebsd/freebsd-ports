PORTNAME=	docling-agent
DISTVERSION=	0.7.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to simplify agentic operations on documents
WWW=		https://github.com/docling-project/docling-agent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.35:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.79.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-slim>=2.140.0:textproc/py-docling-slim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mellea>=0.3:devel/py-mellea@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.2:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=19.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.4:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.10:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
