# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	brian
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	science python

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Clock-driven simulator for spiking neural networks

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.4.1,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:math/py-matplotlib@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	brian-team
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
