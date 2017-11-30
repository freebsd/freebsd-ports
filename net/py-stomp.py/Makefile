# Created by: James Elstone <james@elstone.net>
# $FreeBSD$

PORTNAME=	stomp.py
PORTVERSION=	4.1.17
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	james@elstone.net
COMMENT=	Python STOMP client, supporting >=1.0 and <=1.2 of the protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.1:devel/py-pytest@${FLAVOR}

OPTIONS_DEFINE=	DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
