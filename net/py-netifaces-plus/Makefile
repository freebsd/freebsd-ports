PORTNAME=	netifaces-plus
DISTVERSIONPREFIX=	release_
DISTVERSION=	0_12_5
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Portable network interface information
WWW=		https://pypi.org/project/netifaces-plus/

LICENSE=	MIT

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	tsukumijima
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_TARGET=	test.py
DO_MAKE_TEST=	${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_netifaces*.so

.include <bsd.port.mk>
