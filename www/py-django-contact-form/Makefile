PORTNAME=	django-contact-form
PORTVERSION=	5.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_contact_form-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic contact-form application for Django
WWW=		https://django-contact-form.readthedocs.io/en/stable/ \
		https://github.com/ubernostrum/django-contact-form

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
TEST_ENV=	DJANGO_SETTINGS_MODULE=tests.settings \
		PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
