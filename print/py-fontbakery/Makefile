PORTNAME=	fontbakery
PORTVERSION=	0.8.13
DISTVERSIONPREFIX=	v
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Well designed Font QA tool
WWW=		https://github.com/googlefonts/fontbakery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}axisregistry>=0.3.0:x11-fonts/py-axisregistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beziers>=0.5.0:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmarkgfm>=0:textproc/py-cmarkgfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}collidoscope>=0.5.2:print/py-collidoscope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dehinter>=3.1.0:print/py-dehinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}font-v>=0:print/py-font-v@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.36.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gflanguages>=0.3.0:x11-fonts/py-gflanguages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphsets>=0.5.0:print/py-glyphsets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:math/py-munkres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentype-sanitizer>=7.1.9:x11-fonts/py-opentype-sanitizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentypespec>=0:x11-fonts/py-opentypespec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-api>=0:devel/py-pip-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringbrewer>=0:devel/py-stringbrewer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufo2ft>=2.25.2:x11-fonts/py-ufo2ft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolint>=0:x11-fonts/py-ufolint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodedata2>=0:devel/py-unicodedata2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0.2.0:print/py-vharfbuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	googlefonts
USE_GITHUB=	yes

OPTIONS_DEFINE=	FREETYPE

FREETYPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freetype-py>=0:print/py-freetype-py@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
