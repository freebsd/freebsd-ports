PORTNAME=	docling-metrics-table
DISTVERSION=	0.16.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tree-Edit-Distance Score metric
WWW=		https://github.com/docling-project/docling-metrics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cxxopts>=3.3.1:devel/cxxopts \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.12:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR} \
		loguru>=2.1.0:devel/loguru
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apted>0:math/py-apted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-metrics-core>=0.0.1:textproc/py-docling-metrics-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=0:devel/py-rapidfuzz@${PY_FLAVOR}

USES=		cmake:indirect python localbase pkgconfig
USE_PYTHON=	autoplist concurrent pep517

CMAKE_ARGS=	-DUSE_SYSTEM_DEPS=ON

.include <bsd.port.mk>
