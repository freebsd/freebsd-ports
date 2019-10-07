# $FreeBSD$

PORTNAME=	fontmake
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Compile fonts from sources to binary

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cu2qu>=1.6.5:x11-fonts/py-cu2qu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphsLib>=3.1.3:x11-fonts/py-glyphsLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.5.0:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MutatorMath>=2.1.2:math/py-MutatorMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.6.0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.8.1:x11-fonts/py-booleanOperations@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
