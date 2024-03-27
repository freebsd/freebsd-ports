PORTNAME=	django-tagging
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Generic tagging application for Django
WWW=		https://github.com/Fantomas42/django-tagging

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=0:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
