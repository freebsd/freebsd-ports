# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>

PORTNAME=	tvnamer
PORTVERSION=	3.0.4
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Automatically names downloaded/recorded TV-episode

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tvdb_api>=1.5:www/py-tvdb_api@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tvdb_api>=1.5:www/py-tvdb_api@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.3:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist flavors

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
