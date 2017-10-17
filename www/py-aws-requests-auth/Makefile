# Created by: James Elstone <james@elstone.net>
# $FreeBSD$

PORTNAME=	aws-requests-auth
PORTVERSION=	0.4.0
CATEGORIES=	www python textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	james@elstone.net
COMMENT=	Authenticate to AWS with Amazon's signature v4 signing process

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.1:devel/py-pytest
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.14.0:www/py-requests

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
