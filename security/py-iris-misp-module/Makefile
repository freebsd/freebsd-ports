PORTNAME=	iris-misp-module
DISTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IRIS module interfacing MISP with IRIS
WWW=		https://github.com/dfir-iris/iris-module-interface	

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyunpack>0:archivers/py-pyunpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iris-module-interface>0:security/py-iris-module-interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymisp>0:devel/py-pymisp@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	a7654c086bb163a97987698bae012c6bc05fd300

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
