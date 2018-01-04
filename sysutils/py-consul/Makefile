# $FreeBSD$

PORTNAME=	py-consul
PORTVERSION=	0.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Python client for consul

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR}

USES=	python:3.3+

USE_GITHUB=	yes
GH_ACCOUNT=	cablehead
GH_PROJECT=	python-consul

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
