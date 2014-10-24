# Created by: User & <dragon@njord.localdomain>
# $FreeBSD$

PORTNAME=	sslstrip
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.thoughtcrime.org/software/sslstrip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kitchetech@gmail.com
COMMENT=	Python program for SSL stripping

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}twistedWeb>=0:${PORTSDIR}/www/py-twistedWeb

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
