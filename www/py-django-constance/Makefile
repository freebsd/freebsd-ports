# Created by: Richard Gallamore <ultima@FreeBSD.org>

PORTNAME=	django-constance
PORTVERSION=	2.9.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Dynamic Django settings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-picklefield>=0:www/py-django-picklefield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=1.8:www/py-django32@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jazzband

.include <bsd.port.mk>
