# Created by: Richard Gallamore <ultima@FreeBSD.org>

PORTNAME=	django-webpack-loader
PORTVERSION=	0.7.0
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Transparently use webpack with Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.0:www/py-django22@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

.include <bsd.port.mk>
