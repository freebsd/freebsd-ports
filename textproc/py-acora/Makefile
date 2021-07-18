# Created by: antoine@FreeBSD.org

PORTNAME=	acora
PORTVERSION=	2.3
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Fast multi-keyword search engine for text strings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/scratch	# Any directory different from ${WRKSRC}

do-test:
	@${MKDIR} ${TEST_WRKSRC}
	@${CP} ${WRKSRC}/test.py ${WRKSRC}/README.rst ${TEST_WRKSRC}
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py

.include <bsd.port.mk>
