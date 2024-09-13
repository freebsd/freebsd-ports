PORTNAME=	narwhals
PORTVERSION=	1.4.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
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

OPTIONS_DEFINE=	DASK PANDAS POLARS PYARROW
DASK_DESC=	Dask DataFrame support
PANDAS_DESC=	Pandas API support
POLARS_DESC=	Polars API support
PYARROW_DESC=	PyArrow API support

DASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2024.7:devel/py-dask@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.25.3,1:math/py-pandas@${PY_FLAVOR}
POLARS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}polars>=0.20.3:misc/py-polars@${PY_FLAVOR}
PYARROW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=11.0.0:databases/py-pyarrow@${PY_FLAVOR}

.include <bsd.port.mk>
