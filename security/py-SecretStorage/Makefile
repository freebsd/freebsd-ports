# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	SecretStorage
PORTVERSION=	1.1.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store passwords using the SecretService DBus API

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.84.0:${PORTSDIR}/devel/py-dbus

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
