PORTNAME=	django-libsass
PORTVERSION=	0.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alex@xanderio.de
COMMENT=	Filter to compile SASS files using libsass

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django_compressor>=1.3:www/py-django_compressor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libsass>=0.7.0:www/py-libsass@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
