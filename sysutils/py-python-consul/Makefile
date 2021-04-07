PORTNAME=	python-consul
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Python client for consul

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/consul:sysutils/consul \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/bin/consul:sysutils/consul \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR}

# 2.7 or 3.6+, but it cannot be expressed right now.
USES=	python:3.6+

USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	cablehead

.include <bsd.port.mk>
