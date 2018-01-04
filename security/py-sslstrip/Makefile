# Created by: User & <dragon@njord.localdomain>
# $FreeBSD$

PORTNAME=	sslstrip
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://www.thoughtcrime.org/software/sslstrip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kitchetech@gmail.com
COMMENT=	Python program for SSL stripping

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
