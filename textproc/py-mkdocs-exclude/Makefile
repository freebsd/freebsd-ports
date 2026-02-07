PORTNAME=	mkdocs-exclude
DISTVERSION=	1.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vladislav.movchan@gmail.com
COMMENT=	MkDocs plugin to exclude files from input using globs or regexps
WWW=		https://github.com/apenwarr/mkdocs-exclude

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs>=1.0:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
