PORTNAME=	narwhals
PORTVERSION=	2.2.0
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://github.com/narwhals-dev/narwhals/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely lightweight compatibility layer between dataframe libraries
WWW=		https://narwhals-dev.github.io/narwhals/ \
		https://github.com/narwhals-dev/narwhals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DASK DUCKDB PANDAS MODIN POLARS PYARROW SQLFRAME
DASK_DESC=	Dask DataFrame support
DUCKDB_DESC=	DuckDB API support
PANDAS_DESC=	Pandas API support
MODIN_DESC=	Modin API support
POLARS_DESC=	Polars API support
PYARROW_DESC=	PyArrow API support
SQLFRAME_DESC=	SQLFrame support

DASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2024.8:devel/py-dask@${PY_FLAVOR}
DUCKDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}duckdb>=1.0:databases/py-duckdb@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.1.3,1:math/py-pandas@${PY_FLAVOR}
MODIN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}modin>=0:math/py-modin@${PY_FLAVOR}
POLARS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}polars>=0.20.4:misc/py-polars@${PY_FLAVOR}
PYARROW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=13.0.0:databases/py-pyarrow@${PY_FLAVOR}
SQLFRAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlframe>=3.22.0:databases/py-sqlframe@${PY_FLAVOR}

.include <bsd.port.mk>
