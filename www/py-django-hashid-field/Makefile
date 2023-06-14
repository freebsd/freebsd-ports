PORTNAME=	django-hashid-field
PORTVERSION=	3.3.7
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hashids obfuscated Django Model Field
WWW=		https://github.com/nshafer/django-hashid-field

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.11:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hashids>=1.2.0:textproc/py-hashids@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
