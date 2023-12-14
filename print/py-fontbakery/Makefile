PORTNAME=	fontbakery
PORTVERSION=	0.10.7
CATEGORIES=	print python
MASTER_SITES=	PYPI \
		https://github.com/fonttools/fontbakery/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Well designed Font QA tool
WWW=		https://font-bakery.readthedocs.io/en/latest/ \
		https://github.com/fonttools/fontbakery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfont>=3.0.1:x11-fonts/py-babelfont@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beziers>=0.5.0:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmarkgfm>=0.4:textproc/py-cmarkgfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.39.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freetype-py>=0:print/py-freetype-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:math/py-munkres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentype-sanitizer>=7.1.9:x11-fonts/py-opentype-sanitizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentypespec>=0:x11-fonts/py-opentypespec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-api>=0:devel/py-pip-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	FONTVAL FONTWERK GOOGLEFONTS ISO15008 NOTOFONTS SHAPING TYPENETWORK UFO_SOURCES
OPTIONS_DEFAULT=FONTVAL FONTWERK GOOGLEFONTS ISO15008 NOTOFONTS SHAPING TYPENETWORK UFO_SOURCES
FONTVAL_DESC=		Checks for Font Validator
FONTWERK_DESC=		Checks for Fontwerk.com
FONTWERK_IMPLIES=	GOOGLEFONTS
GOOGLEFONTS_DESC=	Checks for Google Fonts
GOOGLEFONTS_IMPLIES=	SHAPING UFO_SOURCES
ISO15008_DESC=		Checks for suitability for in-car displays (ISO 15008)
NOTOFONTS_DESC=		Checks for Noto fonts
NOTOFONTS_IMPLIES=	GOOGLEFONTS
SHAPING_DESC=		Checks for shaping
TYPENETWORK_DESC=	Checks for Type Network
UFO_SOURCES_DESC=	Checks for UFO sources

FONTVAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
GOOGLEFONTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}axisregistry>=0.4.5:x11-fonts/py-axisregistry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.7.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dehinter>=3.1.0:print/py-dehinter@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}font-v>=0.6.0:print/py-font-v@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fonttools>=4.39.0:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gflanguages>=0.5.10:x11-fonts/py-gflanguages@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}glyphsets>=0.6.6:print/py-glyphsets@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.0,1:devel/py-protobuf@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shaperglot>=0.3.1:x11-fonts/py-shaperglot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0.2.0:print/py-vharfbuzz@${PY_FLAVOR}
ISO15008_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0:print/py-uharfbuzz@${PY_FLAVOR}
SHAPING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collidoscope>=0.5.2:print/py-collidoscope@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shaperglot>=0.3.1:x11-fonts/py-shaperglot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}stringbrewer>=0:devel/py-stringbrewer@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.25.2:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0.2.0:print/py-vharfbuzz@${PY_FLAVOR}
TYPENETWORK_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.7.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shaperglot>=0.3.1:x11-fonts/py-shaperglot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.25.2:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0:print/py-uharfbuzz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0.2.0:print/py-vharfbuzz@${PY_FLAVOR}
UFO_SOURCES_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fonttools>=4.39.0:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.25.2:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ufolint>=0:x11-fonts/py-ufolint@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
