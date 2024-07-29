PORTNAME=	awkward-cpp
PORTVERSION=	35
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CPU kernels and compiled extensions for Awkward Array
WWW=		https://awkward-array.org/doc/main/ \
		https://github.com/scikit-hep/awkward/tree/main/awkward-cpp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.2.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		rapidjson>=0:devel/rapidjson
# scikit-build-core[pyproject]
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathspec>=0.10.1:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.5:devel/py-pyproject-metadata@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.18.0,1:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++11-lang localbase python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/rapidjson/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
