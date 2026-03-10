PORTNAME=	django-recaptcha
PORTVERSION=	4.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_recaptcha-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django reCAPTCHA form field/widget integration app
WWW=		https://github.com/django-recaptcha/django-recaptcha

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>0:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
