PORTNAME=	django-solo
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Helps working with singletons
WWW=		https://github.com/lazybird/django-solo

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.6:www/py-django32@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	lazybird
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
