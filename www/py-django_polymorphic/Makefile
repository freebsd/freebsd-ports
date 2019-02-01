# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django_polymorphic
PORTVERSION=	2.0.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django-polymorphic-${PORTVERSION}

MAINTAINER=	ports@caomhin.org
COMMENT=	Seamless Polymorphic Inheritance for Django Models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
