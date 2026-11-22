PORTNAME=	djangorestframework-csv
DISTVERSION=	3.0.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Django REST framework
WWW=		https://github.com/mjumbewu/django-rest-framework-csv

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}djangorestframework>0,1:www/py-djangorestframework@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

# The sdist ships stale bytecode that setup.py would install as package data
post-extract:
	@${RM} -r ${WRKSRC}/rest_framework_csv/__pycache__

.include <bsd.port.mk>
