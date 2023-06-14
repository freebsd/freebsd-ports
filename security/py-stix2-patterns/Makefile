PORTNAME=	stix2-patterns
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to validate STIX 2 Patterns
WWW=		https://github.com/oasis-open/cti-pattern-validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=0:devel/py-antlr4-python3-runtime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	oasis-open
GH_PROJECT=	cti-pattern-validator

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.mk>
