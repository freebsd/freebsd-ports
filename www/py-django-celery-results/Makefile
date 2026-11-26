PORTNAME=	django-celery-results
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Celery result backends for django
WWW=		https://github.com/celery/django-celery-results

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}celery>=5.3.6:devel/py-celery@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist distutils

CPE_VENDOR=	django-celery-results_project

.include <bsd.port.mk>
