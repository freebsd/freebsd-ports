PORTNAME=	awkward-cpp
PORTVERSION=	47
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	awkward_cpp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CPU kernels and compiled extensions for Awkward Array
WWW=		https://awkward-array.org/doc/main/ \
		https://github.com/scikit-hep/awkward/tree/main/awkward-cpp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR} \
		rapidjson>=0:devel/rapidjson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.18.0,1:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++11-lang localbase python:3.9+
USE_PYTHON=	autoplist concurrent pep517

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/rapidjson/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
