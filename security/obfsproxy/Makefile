# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	obfsproxy
PORTVERSION=	0.2.13
PORTEPOCH=	1
CATEGORIES=	security net python
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyptlib>=0.0.5:security/py-pyptlib \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.1:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml

USE_PYTHON=	distutils
USES=		python twisted
SUB_FILES=	pkg-message
PYDISTUTILS_PKGNAME=obfsproxy

.include <bsd.port.mk>
