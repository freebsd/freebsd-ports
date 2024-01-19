PORTNAME=	pysha3
DISTVERSION=	1.0.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SHA-3 (Keccak) for Python
WWW=		https://bitbucket.org/tiran/pykeccak

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Merged into python standard library since version 3.6
EXPIRATION_DATE=	2024-02-16
BROKEN_mips64=		fails to compile: KeccakP-1600-opt64.c: error: Not yet implemented

# Actually Python 2.7,3.4+
USES=		python:-3.6
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 30600
IGNORE=	Does not support python 3.9 and later
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pysha3*.so

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
