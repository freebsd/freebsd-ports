# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	SecretStorage
PORTVERSION=	2.1.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store passwords using the SecretService DBus API

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.84.0:devel/py3-dbus
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.84.0:devel/py-dbus
.endif

.include <bsd.port.post.mk>
