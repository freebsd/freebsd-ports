PORTNAME=	djangorestframework-guardian
PORTVERSION=	0.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Django Guardian support for Django REST Framework
WWW=		https://github.com/rpkilby/django-rest-framework-guardian

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-djangorestframework>=3.10.3:www/py-dj42-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-guardian>=2.4.0:www/py-dj42-django-guardian@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
