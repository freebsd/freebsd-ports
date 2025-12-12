PORTNAME=	django-bootstrap3
DISTVERSION=	25.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_bootstrap3-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Bootstrap 3 support for Django projects
WWW=		https://github.com/zostera/django-bootstrap3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.6<0.10.0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} manage.py test -v3 --noinput

.include <bsd.port.mk>
