PORTNAME=	iris-misp-module
DISTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IRIS module interfacing MISP with IRIS
WWW=		https://github.com/dfir-iris/iris-misp-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyunpack>0:archivers/py-pyunpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iris-module-interface>0:security/py-iris-module-interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymisp>0:devel/py-pymisp@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	216116cf6e039e8e2bb8ba399f1c65674a8af008

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
