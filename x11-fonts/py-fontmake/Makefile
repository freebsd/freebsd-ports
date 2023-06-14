PORTNAME=	fontmake
PORTVERSION=	3.5.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Compile fonts from sources to binary
WWW=		https://github.com/googlefonts/fontmake

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.9.3:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.38.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphsLib>=6.1.0:x11-fonts/py-glyphsLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.29.0:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolib2>=0.13.0:print/py-ufolib2@${PY_FLAVOR} \

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AUTOHINT MUTATORMATH
OPTIONS_DEFAULT=AUTOHINT MUTATORMATH
AUTOHINT_DESC=	ttfautohint support
MUTATORMATH_DESC=	Allow use mutatormath instead of internal instantiator

AUTOHINT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ttfautohint-py>=0.5.0:print/py-ttfautohint-py@${PY_FLAVOR}
MUTATORMATH_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}MutatorMath>=2.1.2:math/py-MutatorMath@${PY_FLAVOR}

.include <bsd.port.mk>
