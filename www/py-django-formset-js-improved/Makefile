PORTNAME=	django-formset-js-improved
DISTVERSION=	0.5.0.5
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_formset_js_improved-${DISTVERSION}

MAINTAINER=	alex@xanderio.de
COMMENT=	Fork of django-formset-js that adds support for reordering and nested formsets
WWW=		https://github.com/pretix/django-formset-js

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=1.8:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-jquery-js>=0.:www/py-django-jquery-js@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
