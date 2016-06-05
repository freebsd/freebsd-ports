# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	pytoport
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Generate FreeBSD ports from Python modules on PyPI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GH_ACCOUNT=	freebsd
GH_PROJECT=	pytoport

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}spdx-lookup>=0.3.0:misc/py-spdx-lookup \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils

USES=		python:3.3+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
