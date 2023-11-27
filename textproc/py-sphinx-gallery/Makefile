PORTNAME=	sphinx-gallery
PORTVERSION=	0.15.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx extension that builds an HTML gallery of examples from any set of Python scripts
WWW=		https://sphinx-gallery.github.io/stable/ \
		https://github.com/sphinx-gallery/sphinx-gallery

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=4,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
