PORTNAME=	django-formset-js-improved
PORTVERSION=	0.5.0.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alex@xanderio.de
COMMENT=	Fork of django-formset-js that adds support for reordering and nested formsets
WWW=		https://github.com/pretix/django-formset-js

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.8:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-jquery-js>=0.:www/py-django-jquery-js@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
