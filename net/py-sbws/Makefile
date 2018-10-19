# $FreeBSD$

PORTNAME=		sbws
PORTVERSION=		0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=		net python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Tor network bandwidth scanner

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=1.7.0:security/py-stem@${PY_FLAVOR} \
		tor:security/tor

USES=		cpe python:3.5+ shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils flavors

CPE_VENDOR=	torproject
GH_ACCOUNT=	torproject

SHEBANG_FILES=	tests/testnets/simple.common/03-network-in-ready-state.py \
		tests/testnets/simple-ipv4/03-network-in-ready-state.py \
		tests/testnets/simple-ipv6/03-network-in-ready-state.py

.include <bsd.port.mk>
