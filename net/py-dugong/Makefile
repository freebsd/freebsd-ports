# $FreeBSD$

PORTNAME=	dugong
PORTVERSION=	3.7.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	niklaas@kulturflatrate.net
COMMENT=	HTTP 1.1 client module designed for RESTful protocols

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

NO_ARCH=	yes

USES=		python:3.3+ tar:bzip2
USE_PYTHON=	autoplist distutils

do-test:
	${PYTHON_CMD} -m pytest ${WRKSRC}/test

.include <bsd.port.mk>
