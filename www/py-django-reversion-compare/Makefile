PORTNAME=	django-reversion-compare
DISTVERSION=	0.21.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_reversion_compare-${DISTVERSION}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Extension to django-reversion that provides a history compare view
WWW=		https://github.com/jedie/django-reversion-compare

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diff-match-patch>0:textproc/py-diff-match-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-reversion>0:www/py-django-reversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=0:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
