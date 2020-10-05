# $FreeBSD$

PORTNAME=	resolve-march-native
DISTVERSION=	1.0.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Command line tool to resolve -march=native into explicit flags

LICENSE=	GPLv2+

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	hartwork
USE_PYTHON=	autoplist concurrent distutils

ALL_TARGET=	install
BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes

.include <bsd.port.mk>
