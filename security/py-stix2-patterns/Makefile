PORTNAME=	stix2-patterns
PORTVERSION=	2.1.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	stix2_patterns-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to validate STIX 2 Patterns
WWW=		https://github.com/oasis-open/cti-pattern-validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=4.13.0,1<4.14,1:devel/py-antlr4-python3-runtime@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
