PORTNAME=	python-nomad
PORTVERSION=	1.2.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Python client for nomad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR}

USES=	python:3.3+

USE_GITHUB=	yes
GH_ACCOUNT=	jrxFive
GH_PROJECT=	python-nomad

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
