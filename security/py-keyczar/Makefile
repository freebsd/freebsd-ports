# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyczar
PORTVERSION=	0.71c
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Toolkit for safe and simple cryptography

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	python-${PORTNAME}

.include <bsd.port.mk>
