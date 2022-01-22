# Created by: Kevin Golding <ports@caomhin.org>

PORTNAME=	django-registration
PORTVERSION=	3.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	User-registration application for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}confusable_homoglyphs>=3.0<4.0:devel/py-confusable_homoglyphs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-registration-redux

NO_ARCH=	yes

.include <bsd.port.mk>
