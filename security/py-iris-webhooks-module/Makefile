PORTNAME=	iris-webhooks-module
DISTVERSION=	1.0.4
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IRIS module offering support for webhooks
WWW=		https://github.com/dfir-iris/iris-webhooks-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iris-module-interface>0:security/py-iris-module-interface@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	e120303fd8c46f4d29a9c7fea3d8c8acae176505

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
