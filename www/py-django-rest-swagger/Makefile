PORTNAME=	django-rest-swagger
DISTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Swagger UI for Django REST framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Has expired: Upstream no longer maintained, please use www/py-drf-yasg instead
EXPIRATION_DATE=	2021-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coreapi>0:devel/py-coreapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>0:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-codec>0:devel/py-openapi-codec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
