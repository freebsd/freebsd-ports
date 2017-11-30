# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyczar
PORTVERSION=	0.716
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Toolkit for safe and simple cryptography

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${FLAVOR}

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
