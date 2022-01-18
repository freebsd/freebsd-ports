PORTNAME=	django-taggit
PORTVERSION=	2.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj32-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Reusable Django application for simple tagging

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj32-djangorestframework>0:www/py-dj32-djangorestframework@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj31-django-taggit \
			${PYTHON_PKGNAMEPREFIX}django-taggit

NO_ARCH=		yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m django test --settings=tests.settings -v3

.include <bsd.port.mk>
