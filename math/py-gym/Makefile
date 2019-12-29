# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gym
PORTVERSION=	0.15.4
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenAI toolkit for developing and comparing your reinforcement learning agents

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=1.2.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyglet12>=1.2.0<1.3.3:graphics/py-pyglet12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|, 'opencv-python'||" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e '/opencv-python/d' ${WRKSRC}/gym.egg-info/requires.txt

.include <bsd.port.mk>
