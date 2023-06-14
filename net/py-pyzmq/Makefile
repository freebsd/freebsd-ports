PORTNAME=	pyzmq
DISTVERSION=	25.0.2
CATEGORIES=	net devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for ZeroMQ
WWW=		https://github.com/zeromq/pyzmq

LICENSE=			BSD3CLAUSE LGPL3
LICENSE_COMB=			multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_LGPL3=		${WRKSRC}/LICENSE.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		python
USE_PYTHON=	distutils autoplist cython pytest # 3 tests fail, see https://github.com/zeromq/pyzmq/issues/1802

PYDISTUTILS_CONFIGUREARGS=	--zmq=${LOCALBASE}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zmq/backend/cython/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zmq/devices/*.so

.include <bsd.port.mk>
