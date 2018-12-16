# $FreeBSD$

PORTNAME=	cu2qu
PORTVERSION=	1.6.4
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Cubic-to-quadratic bezier curve conversion

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.18.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoLib>=2.1.1:x11-fonts/py-ufoLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.4.0:x11-fonts/py-defcon@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
