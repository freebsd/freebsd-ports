PORTNAME=	sphinxcontrib-svg2pdfconverter
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	agh@riseup.net
COMMENT=	Sphinx extension for converting SVG to PDF
WWW=		https://github.com/missinglinkelectronics/sphinxcontrib-svg2pdfconverter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	librsvg2
USE_PYTHON=	autoplist concurrent distutils flavors

NO_ARCH=	yes

.include <bsd.port.mk>
