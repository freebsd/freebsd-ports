# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyzmq
PORTVERSION=	16.0.1
CATEGORIES=	net devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for ZeroMQ

LICENSE=	LGPL3

LIB_DEPENDS=	libzmq.so:net/libzmq4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest

USES=		python
USE_PYTHON=	distutils autoplist
PYDISTUTILS_CONFIGUREARGS=	--zmq=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>0:devel/py-asyncio
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>
