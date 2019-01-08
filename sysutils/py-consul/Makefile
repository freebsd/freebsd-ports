# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Python client for consul

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/consul:sysutils/consul \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/bin/consul:sysutils/consul \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR}

USES=	python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	cablehead
GH_PROJECT=	python-consul

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
