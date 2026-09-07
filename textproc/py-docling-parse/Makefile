PORTNAME=	docling-parse
DISTVERSION=	7.17.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple package to extract text with coordinates from programmatic PDFs
WWW=		https://github.com/docling-project/docling-parse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.13.6:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cxxopts>=3.3.1:devel/cxxopts \
		loguru>=2.1.0:devel/loguru \
		nlohmann-json>=3.12.0:devel/nlohmann-json \
		utf8cpp>=4.1.1:devel/utf8cpp
LIB_DEPENDS=	libblend2d.so:graphics/blend2d \
			libfreetype.so:print/freetype2 \
		libjpeg.so:graphics/jpeg-turbo \
		liblcms2.so:graphics/lcms2 \
		libopenjp2.so:graphics/openjpeg \
		libqpdf.so:print/qpdf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-core>=2.95.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR}

USES=		cmake:indirect python localbase pkgconfig
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	USE_SYSTEM_DEPS=ON

.include <bsd.port.mk>
