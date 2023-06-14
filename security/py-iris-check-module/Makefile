PORTNAME=	iris-check-module
DISTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A simple processor module for IRIS
WWW=		https://github.com/dfir-iris/iris-check-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>0:devel/py-celery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyunpack>0:archivers/py-pyunpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iris-module-interface>0:security/py-iris-module-interface@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	b939e036b44f63b810fe5ff43329fad52c6beaeb

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
