# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyzmq
PORTVERSION=	18.0.0
CATEGORIES=	net devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for ZeroMQ

LICENSE=			BSD3CLAUSE LGPL3
LICENSE_COMB=			multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING.BSD
LICENSE_FILE_LGPL3=		${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libzmq.so:net/libzmq4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

PYDISTUTILS_CONFIGUREARGS=	--zmq=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>0:devel/py-asyncio@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zmq/backend/cython/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zmq/devices/*.so

.include <bsd.port.post.mk>
