PORTNAME=	mkdocs-mermaid2-plugin
DISTVERSION=	0.6.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samir@noir.im
COMMENT=	MkDocs plugin for including mermaid graphs in markdown sources
WWW=		https://github.com/fralau/mkdocs-mermaid2-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsbeautifier>0:devel/py-jsbeautifier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=0:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>0:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
