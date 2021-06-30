# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	fontbakery
PORTVERSION=	0.7.38
DISTVERSIONPREFIX=	v
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Well designed Font QA tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beziers>=0:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmarkgfm>=0:textproc/py-cmarkgfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}collidoscope>=0:print/py-collidoscope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dehinter>=3.1.0:print/py-dehinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}font-v>=0:print/py-font-v@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.34:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentype-sanitizer>=7.1.9:x11-fonts/py-opentype-sanitizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-api>=0:devel/py-pip-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringbrewer>=0:devel/py-stringbrewer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolint>=0:x11-fonts/py-ufolint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vharfbuzz>=0:print/py-vharfbuzz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	googlefonts
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
