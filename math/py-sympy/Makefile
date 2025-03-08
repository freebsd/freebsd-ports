PORTNAME=	sympy
PORTVERSION=	1.13.3
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library For Symbolic Mathematics
WWW=		https://sympy.org/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpmath>=1.1.0:math/py-mpmath@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest
NO_ARCH=	yes

OPTIONS_DEFINE=	PYGLET
PYGLET_DESC=	Enable plotting support

PYGLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet1>=1.1.2:graphics/py-pyglet1@${PY_FLAVOR}

.include <bsd.port.mk>
