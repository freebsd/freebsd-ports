# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	requests
PORTVERSION=	2.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.3.4:${PORTSDIR}/devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	py*-requests1-*

NO_ARCH=	yes

# FAIL: test_response_iter_lines_reentrant (test_requests.RequestsTestCase)
# Is marked xfail, but pytest doesn't seem to recognize it.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
