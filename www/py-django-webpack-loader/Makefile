PORTNAME=	django-webpack-loader
PORTVERSION=	2.0.1
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Transparently use webpack with Django
WWW=		https://pypi.org/project/django-webpack-loader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.0:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

.include <bsd.port.mk>
