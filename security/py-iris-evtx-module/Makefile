PORTNAME=	iris-evtx-module
DISTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Example of IRIS module, handling EVTX files
WWW=		https://github.com/dfir-iris/iris-evtx-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>0:devel/py-celery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyunpack>0:archivers/py-pyunpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evtx2splunk>0:textproc/py-evtx2splunk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iris-module-interface>0:security/py-iris-module-interface@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	4845709c26bc1a5aa2528077749ec1f61985175f

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
