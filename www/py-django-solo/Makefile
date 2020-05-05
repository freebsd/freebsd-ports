# $FreeBSD$

PORTNAME=	django-solo
DISTVERSION=	1.1.3-8
DISTVERSIONSUFFIX=	-g3dcd6ab
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Helps working with singletons

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.6:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	lazybird
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
