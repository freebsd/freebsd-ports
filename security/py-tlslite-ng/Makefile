PORTNAME=	tlslite-ng
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure python implementation of SSL and TLS
WWW=		https://github.com/tlsfuzzer/tlslite-ng

LICENSE=	BSD3CLAUSE LGPL21 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>=0:security/py-ecdsa@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
