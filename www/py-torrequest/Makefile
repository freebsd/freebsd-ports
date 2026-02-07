PORTNAME=	torrequest
DISTVERSION=	0.1.0
CATEGORIES=	www security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Simple interface for HTTP(s) requests over Tor
WWW=		https://github.com/erdiaker/torrequest

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.7:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=1.4.0:security/py-stem@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
