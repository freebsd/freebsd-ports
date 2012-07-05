# New ports collection makefile for:	py-rsa
# Date created:		2012-05-24
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rsa
PORTVERSION=	3.1.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Pure-Python RSA implementation

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.3:${PORTSDIR}/devel/py-asn1

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
