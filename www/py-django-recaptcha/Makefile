PORTNAME=	django-recaptcha
PORTVERSION=	4.0.0
CATEGORIES=	www python
MASTER_SITES=	PYPI

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django reCAPTCHA form field/widget integration app
WWW=		https://github.com/django-recaptcha/django-recaptcha

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.11<4.0:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
