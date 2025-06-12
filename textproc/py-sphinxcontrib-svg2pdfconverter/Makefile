PORTNAME=	sphinxcontrib-svg2pdfconverter
DISTVERSION=	1.2.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sphinx extension for converting SVG to PDF
WWW=		https://github.com/missinglinkelectronics/sphinxcontrib-svg2pdfconverter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GNOME=	librsvg2
USE_PYTHON=	autoplist concurrent flavors pep517

NO_ARCH=	yes

OPTIONS_DEFAULT=	CAIROSVG
OPTIONS_GROUP=		RENDERER
OPTIONS_GROUP_RENDERER=	CAIROSVG INKSCAPE RSVG

CAIROSVG_DESC=	Python Cairo SVG
INKSCAPE_DESC=	Inkscape
RENDERER_DESC=	SVG to PDF runtime renderer
RSVG_DESC=	Rust librsvg2 (graphics/librsvg2)

CAIROSVG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairosvg>0:graphics/py-cairosvg@${PY_FLAVOR}
INKSCAPE_RUN_DEPENDS=	inkscape>0:graphics/inkscape
RSVG_USES=		gnome
RSVG_USE=		GNOME=librsvg2

.include <bsd.port.mk>
