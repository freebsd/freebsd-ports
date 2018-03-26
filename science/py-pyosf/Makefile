# $FreeBSD$

PORTNAME=	pyosf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python lib for synching with OpenScienceFramework projects

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	psychopy
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
