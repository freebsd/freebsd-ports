PORTNAME=	langgraph-checkpoint-postgres
DISTVERSION=	3.2.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
MASTER_SITE_SUBDIR=	source/l/langgraph-checkpoint-postgres
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangGraph: Postgres implementation of LangGraph checkpoint saver
WWW=		https://github.com/langchain-ai/langgraph/tree/main/libs/checkpoint-postgres

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=4.3.0:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.11.5:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-pool>=3.2.0:databases/py-psycopg-pool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.2.0:databases/py-psycopg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
