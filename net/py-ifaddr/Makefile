# Created by: John Hixson<jhixson@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ifaddr
PORTVERSION=	0.1.6
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Python Library to enumerate all network interfaces

LICENSE=	MIT

USES=		python:2.7+

USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	pydron

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} < 3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddress>0:net/py-ipaddress
.endif

.include <bsd.port.post.mk>
