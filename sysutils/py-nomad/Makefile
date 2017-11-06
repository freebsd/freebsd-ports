# $FreeBSD$

PORTNAME=	py-nomad
PORTVERSION=	0.5.0
CATEGORIES=	sysutils

MAINTAINER=	jhixson@gmail.com
COMMENT=	Python client for nomad

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py3-requests
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py3-requests

USES=	python:3.3+

USE_GITHUB=	yes
GH_ACCOUNT=	jrxFive
GH_PROJECT=	python-nomad

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
