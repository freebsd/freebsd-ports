PORTNAME=	iris-client
DISTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Python client for DFIR-IRIS
WWW=		https://github.com/dfir-iris/iris-client

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=0:devel/py-deprecated@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
