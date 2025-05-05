PORTNAME=	django-guardian
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Implementation of per object permissions for Django
WWW=		https://github.com/django-guardian/django-guardian

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=5.1:www/py-django51@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
