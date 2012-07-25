# New ports collection makefile for:	py-rackspace-monitoring
# Date created:				2012-06-17
# Whom:					koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rackspace-monitoring
PORTVERSION=	0.3.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python client library for Rackspace Cloud Monitoring

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>=0.9.0:${PORTSDIR}/net/py-libcloud

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
