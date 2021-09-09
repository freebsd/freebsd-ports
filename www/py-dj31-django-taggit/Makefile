PORTNAME=	django-taggit
PORTVERSION=	1.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Reusable Django application for simple tagging

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 3.1 ends December 2021, upgrade to the Django 3.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2021-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.2:www/py-django31@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj31-djangorestframework>0:www/py-dj31-djangorestframework@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-taggit \
			${PYTHON_PKGNAMEPREFIX}dj32-django-taggit

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m django test --settings=tests.settings -v3

.include <bsd.port.mk>
