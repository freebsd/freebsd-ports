# $FreeBSD$

PORTNAME=	zsm
PORTVERSION=	0.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	mattias.lindvall@gmail.com
COMMENT=	ZFS Snapshot Manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pid>=2.2.0:devel/py-pid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zsm-lib>=0.2.0:devel/py-zsm-lib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.6.4:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} LC_ALL=en_US.UTF-8 ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
