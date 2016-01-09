# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	spdx-lookup
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	SPDX license list query tool

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}spdx>0:${PORTSDIR}/misc/py-spdx

USES=		python:3.2+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
