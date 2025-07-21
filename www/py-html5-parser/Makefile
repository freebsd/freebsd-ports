PORTNAME=	html5-parser
PORTVERSION=	0.4.12
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Fast implementation of the HTML 5 parsing spec for Python
WWW=		https://html5-parser.readthedocs.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.9.2:devel/py-lxml5@${PY_FLAVOR}

USES=		gnome pkgconfig python
USE_PYTHON=	autoplist distutils
USE_GNOME=	libxml2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/html5_parser/html_parser*.so

.include <bsd.port.mk>
