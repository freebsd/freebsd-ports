PORTNAME=	django-jquery-js
PORTVERSION=	3.1.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alex@xanderio.de
COMMENT=	jQuery, bundled up so apps can depend upon it
WWW=		https://pypi.org/project/django-jquery-js/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=1.4:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
