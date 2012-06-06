# New ports collection makefile for:	py-slumber
# Date created:		2012-06-02
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	slumber
PORTVERSION=	0.4.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	A Python library that makes consuming a REST API easier

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
