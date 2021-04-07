PORTNAME=	stix2
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to produce and consume STIX 2 JSON content

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stix2-patterns>=0:security/py-stix2-patterns@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	oasis-open
GH_PROJECT=	cti-python-stix2

NO_ARCH=	yes
USES=		python:3.5+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
