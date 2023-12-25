PORTNAME=	mkdocs-minify-plugin
PORTVERSION=	0.7.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minify HTML, JS or CSS files prior to being written to disk
WWW=		https://github.com/byrnereese/mkdocs-minify-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}csscompressor>=0.9.5:www/py-csscompressor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}htmlmin2>=0.1.13:textproc/py-htmlmin2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsmin>=3.0.1:devel/py-jsmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.4.1:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
