PORTNAME=	ufo2ft
PORTVERSION=	3.9.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bridge between UFOs and FontTools
WWW=		https://github.com/googlefonts/ufo2ft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffsubr>=0.3.0:x11-fonts/py-cffsubr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.9.3:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.61.1:print/py-fonttools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COMPREFFOR
OPTIONS_DEFAULT=COMPREFFOR
COMPREFFOR_DESC=CFF subroutinizer support

COMPREFFOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}compreffor>=0.5.4:x11-fonts/py-compreffor@${PY_FLAVOR}

.include <bsd.port.mk>
