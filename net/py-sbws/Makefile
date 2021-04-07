PORTNAME=		sbws
PORTVERSION=		1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=		net python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Tor network bandwidth scanner

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

		# pysocks: indirect dependency via requests[socks]
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.6.8:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=1.7.0:security/py-stem@${PY_FLAVOR} \
		tor:security/tor

USES=		cpe python:3.5+ shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils concurrent flavors

CPE_VENDOR=	torproject
GH_ACCOUNT=	torproject

SHEBANG_FILES=	setup.py \
		scripts/tools/get-per-relay-budget.py \
		scripts/tools/sbws-http-server.py \
		scripts/tools/scale-v3bw-with-budget.py \
		tests/integration/net/wait.py

.include <bsd.port.mk>
