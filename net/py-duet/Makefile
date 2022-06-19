PORTNAME=	duet
PORTVERSION=	0.2.7
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple future-based async library for python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.8+ # 3.7 requires extra-dependencies
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
