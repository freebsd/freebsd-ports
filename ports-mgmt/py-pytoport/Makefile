# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	pytoport
PORTVERSION=	0.4.0
CATEGORIES=	ports-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Generate FreeBSD ports from Python modules on PyPI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}spdx-lookup>=0.3.0:misc/py-spdx-lookup

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
