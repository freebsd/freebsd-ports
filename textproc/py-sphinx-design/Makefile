PORTNAME=	sphinx-design
PORTVERSION=	0.6.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_design-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx extension for designing beautiful, view size responsive web components
WWW=		https://sphinx-design.readthedocs.io/en/latest/ \
		https://github.com/executablebooks/sphinx-design

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=5,1<9,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
