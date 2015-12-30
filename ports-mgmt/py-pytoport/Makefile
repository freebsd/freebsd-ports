# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	pytoport
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Generate FreeBSD ports from Python modules on PyPI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-licensee>0:${PORTSDIR}/devel/rubygem-licensee

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

USES=		python:3.2+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
