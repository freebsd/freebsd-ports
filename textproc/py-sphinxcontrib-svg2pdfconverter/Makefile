PORTNAME=	sphinxcontrib-svg2pdfconverter
PORTVERSION=	1.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinxcontrib_svg2pdfconverter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx SVG to PDF converter extension
WWW=		https://github.com/missinglinkelectronics/sphinxcontrib-svg2pdfconverter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6.3,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_GROUP=	CONVERTER
OPTIONS_GROUP_CONVERTER=CAIROSVG INKSCAPE LIBRSVG
OPTIONS_DEFAULT=CAIROSVG
CAIROSVG_DESC=	Use CairoSVG to convert
INKSCAPE_DESC=	Use inkscape to convert
LIBRSVG_DESC=	Use rsvg-convert to convert

CAIROSVG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairosvg>=1.0:graphics/py-cairosvg@${PY_FLAVOR}
INKSCAPE_RUN_DEPENDS=	inkscape:graphics/inkscape
LIBRSVG_USE=		GNOME=librsvg2
LIBRSVG_USES=		gnome

.include <bsd.port.mk>
