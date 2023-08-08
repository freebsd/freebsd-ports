PORTNAME=	stomp.py
PORTVERSION=	8.0.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	james@elstone.net
COMMENT=	Python STOMP client, supporting >=1.0 and <=1.2 of the protocol
WWW=		https://github.com/jasonrbriggs/stomp.py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.2:devel/py-docopt@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.1:devel/py-pytest@${PY_FLAVOR}

USES=		python

OPTIONS_DEFINE=		DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
