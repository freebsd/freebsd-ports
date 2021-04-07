PORTNAME=	haproxyctl
PORTVERSION=	0.5
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zhoutao@laocius.org
COMMENT=	HAProxy control tool

LICENSE=	GPLv3

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	neurogeek

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v haproxy/tests

.include <bsd.port.mk>
