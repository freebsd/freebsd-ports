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

USES=		python
USE_PYTHON=	distutils autoplist

DEPRECATED=	use textproc/asciinema instead
EXPIRATION_DATE=	2015-07-23

.include <bsd.port.mk>
