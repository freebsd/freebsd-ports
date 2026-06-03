PORTNAME=	django-simple-captcha
PORTVERSION=	0.6.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-
DISTNAME=	django_simple_captcha-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, yet powerful, Django captcha application
WWW=		https://pypi.org/project/django-simple-captcha/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Serves as a transition only for www/seahub and requires Django 4.2, which has been end-of-life since April
EXPIRATION_DATE=2026-08-31

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-ranged-response>=0.2.0<0.2.0_99:www/py-dj42-django-ranged-response@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.2.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
