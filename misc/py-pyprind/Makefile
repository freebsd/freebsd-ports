# $FreeBSD$

PORTNAME=	pyprind
PORTVERSION=	2.9.8
DISTVERSIONPREFIX=	v
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyPrind-${PORTVERSION}

MAINTAINER=	neel@neelc.org
COMMENT=	Python Progress Bar and Percent Indicator Utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}psutil>=0.5.1:sysutils/py-psutil

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PSUTIL

PSUTIL_DESC=		Support monitoring CPU and memory usage
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0.5.1:sysutils/py-psutil

test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
