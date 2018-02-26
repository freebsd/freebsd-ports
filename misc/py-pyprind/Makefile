# $FreeBSD$

PORTNAME=	pyprind
PORTVERSION=	2.11.2
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyPrind-${PORTVERSION}

MAINTAINER=	neel@neelc.org
COMMENT=	Python Progress Bar and Percent Indicator Utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.2.0:sysutils/py-psutil@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PSUTIL

PSUTIL_DESC=		Support monitoring CPU and memory usage
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=3.2.0:sysutils/py-psutil@${FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
