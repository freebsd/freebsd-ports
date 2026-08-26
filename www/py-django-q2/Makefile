PORTNAME=	django-q2
DISTVERSION=	1.11.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_q2-${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Multiprocessing distributed task queue for Django
WWW=		https://django-q2.readthedocs.io/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.10.7:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-picklefield>=3.1:www/py-django-picklefield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>0:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
