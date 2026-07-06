PORTNAME=	mlflow-skinny
PORTVERSION=	3.14.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mlflow_skinny-${PORTVERSION}
DISTFILES=	mlflow_skinny-${PORTVERSION}.tar.gz \
		mlflow_tracing-${PORTVERSION}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight MLflow package with minimal dependencies
WWW=		https://mlflow.org \
		https://github.com/mlflow/mlflow

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=5.0.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}databricks-sdk>=0.20.0:devel/py-databricks-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.9:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.7.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.9.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-proto>=1.9.0:devel/py-opentelemetry-proto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.9.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.12.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.19.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.17.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.4.0:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>0:www/py-uvicorn@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist concurrent

SHEBANG_FILES=	mlflow/assistant/skills/agent-evaluation/scripts/validate_agent_tracing.py \
		mlflow/assistant/skills/querying-mlflow-metrics/scripts/fetch_metrics.py

NO_ARCH=	yes

post-extract:
	@${TAR} -xzf ${DISTDIR}/mlflow_tracing-${PORTVERSION}.tar.gz -C ${WRKDIR}

post-install:
	@cd ${WRKDIR}/mlflow_tracing-${PORTVERSION} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m pip install --no-deps --no-compile --no-build-isolation --ignore-installed --root ${STAGEDIR} --prefix ${PREFIX} .
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/mlflow_tracing-${PORTVERSION}.dist-info

.include <bsd.port.mk>
