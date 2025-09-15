PORTNAME=	fontbakery
PORTVERSION=	1.0.1
PORTREVISION=	2
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beziers>=0.6.0<0.7:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmarkgfm>=0.4:textproc/py-cmarkgfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dehinter>=3.1.0:print/py-dehinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.47.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freetype-py>=0:print/py-freetype-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:math/py-munkres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentype-sanitizer>=9.1.0<10:x11-fonts/py-opentype-sanitizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentypespec>=1.9.2:x11-fonts/py-opentypespec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14.5:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-api>=0:devel/py-pip-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.25.2:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolint>=0:x11-fonts/py-ufolint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0:print/py-uharfbuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0.2.0:print/py-vharfbuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# fontbakery[adobefonts], fontbakery[iso15008] and fontbakery[microsoft] are empty
OPTIONS_DEFINE=	FONTVAL FONTWERK GOOGLEFONTS NOTOFONTS TYPENETWORK
OPTIONS_DEFAULT=FONTVAL FONTWERK GOOGLEFONTS NOTOFONTS TYPENETWORK
FONTVAL_DESC=		Checks for Font Validator
FONTWERK_DESC=		Checks for Fontwerk.com
FONTWERK_IMPLIES=	GOOGLEFONTS
GOOGLEFONTS_DESC=	Checks for Google Fonts
NOTOFONTS_DESC=		Checks for Noto fonts
NOTOFONTS_IMPLIES=	GOOGLEFONTS
TYPENETWORK_DESC=	Checks for Type Network

FONTVAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
GOOGLEFONTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}axisregistry>=0.4.12<0.5:x11-fonts/py-axisregistry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.7.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}collidoscope>=0.5.2:print/py-collidoscope@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gflanguages>=0.7.3<0.8:x11-fonts/py-gflanguages@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gfsubsets>=2024.9.25:x11-fonts/py-gfsubsets@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}glyphsets>=1.1.0<2:print/py-glyphsets@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.0,1:devel/py-protobuf@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shaperglot>=1.0.2<2:x11-fonts/py-shaperglot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}stringbrewer>=0:devel/py-stringbrewer@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}unicodedata2>=0:devel/py-unicodedata2@${PY_FLAVOR}
TYPENETWORK_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.7.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shaperglot>=1.0.0<2:x11-fonts/py-shaperglot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}unicodedata2>=0:devel/py-unicodedata2@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
