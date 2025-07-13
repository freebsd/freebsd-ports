PORTNAME=	pyzmq
DISTVERSION=	27.0.0
PORTREVISION=	0
CATEGORIES=	net devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for ZeroMQ
WWW=		https://github.com/zeromq/pyzmq

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cmake:devel/cmake-core \
                ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.1.5:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		python
USE_PYTHON=	autoplist cython3 pep517 pytest

PYDISTUTILS_CONFIGUREARGS=	--zmq=${LOCALBASE}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zmq/backend/cython/*.so

.include <bsd.port.mk>
