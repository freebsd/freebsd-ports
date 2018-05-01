# $FreeBSD$

PORTNAME=	django-rest-swagger
DISTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Swagger UI for Django REST framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coreapi>0:devel/py-coreapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>0:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-codec>0:devel/py-openapi-codec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
