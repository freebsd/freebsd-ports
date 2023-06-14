PORTNAME=	ufo2ft
PORTVERSION=	2.30.0
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Bridge between UFOs and FontTools
WWW=		https://github.com/googlefonts/ufo2ft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffsubr>=0.2.8:x11-fonts/py-cffsubr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cu2qu>=1.6.7:x11-fonts/py-cu2qu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.38.0:print/py-fonttools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	COMPREFFOR
OPTIONS_DEFAULT=COMPREFFOR
COMPREFFOR_DESC=CFF subroutinizer support

COMPREFFOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}compreffor>=0.4.6:x11-fonts/py-compreffor@${PY_FLAVOR}

.include <bsd.port.mk>
