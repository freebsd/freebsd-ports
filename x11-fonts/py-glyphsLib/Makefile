PORTNAME=	glyphsLib
PORTVERSION=	6.1.0
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Bridge from Glyphs source files (.glyphs) to UFOs
WWW=		https://github.com/googlefonts/glyphsLib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.33.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openstep-plist>=0.3.0:textproc/py-openstep-plist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolib2>=0.6.2:print/py-ufolib2@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DEFCON UFO_NORMALIZATION
OPTIONS_DEFAULT=DEFCON UFO_NORMALIZATION
DEFCON_DESC=	UFO support via py-defcon
UFO_NORMALIZATION_DESC=	Normalize UFOs with py-ufonormalizer

DEFCON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defcon>=0.6.0:x11-fonts/py-defcon@${PY_FLAVOR}
UFO_NORMALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0:x11-fonts/py-ufonormalizer@${PY_FLAVOR}

.include <bsd.port.mk>
