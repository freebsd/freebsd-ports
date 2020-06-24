# $FreeBSD$

PORTNAME=	django-extensions
PORTVERSION=	2.2.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	ports@caomhin.org
COMMENT=	Global custom management extensions for the Django Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-extensions instead
EXPIRATION_DATE=	2020-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.2:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-extensions

.include <bsd.port.mk>
