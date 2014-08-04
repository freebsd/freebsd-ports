# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	asciinema
PORTVERSION=	0.9.8
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for recording and sharing terminal sessions

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:${PORTSDIR}/www/py-requests

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
