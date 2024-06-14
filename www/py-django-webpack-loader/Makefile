PORTNAME=	django-webpack-loader
PORTVERSION=	3.1.0
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Transparently use webpack with Django
WWW=		https://pypi.org/project/django-webpack-loader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.0:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

.include <bsd.port.mk>
