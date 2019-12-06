# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-extensions
PORTVERSION=	2.1.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Global custom management extensions for the Django Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.2:devel/py-six@${PY_FLAVOR} \
		${PY_TYPING}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj22-django-extensions

.include <bsd.port.mk>
