# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-registration
PORTVERSION=	2.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	User-registration application for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}confusable_homoglyphs>=0:devel/py-confusable_homoglyphs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django>=1.8:www/py-django@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	pootle ${PYTHON_PKGNAMEPREFIX}django-registration-redux

.include <bsd.port.mk>
