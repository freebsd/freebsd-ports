# $FreeBSD$

PORTNAME=	ufo2ft
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Bridge between UFOs and FontTools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.6.0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cu2qu>=1.6.4:x11-fonts/py-cu2qu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}compreffor>=0.4.5:x11-fonts/py-compreffor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.8.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PY_ENUM34}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
