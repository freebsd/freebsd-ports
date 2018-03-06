# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-hijack
PORTVERSION=	2.1.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Allows DJango superusers to login as other users

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.8:www/py-django@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
