PORTNAME=	rstfmt
DISTVERSION=	0.0.10
CATEGORIES=	textproc devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Formatter for reStructuredText

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Sphinix should be < 4.0 for now: https://github.com/dzhu/rstfmt/issues/12
BROKEN=	Doesn't work with Sphinx 4 or greater

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.3.2:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>=19.10b0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=2.4.0,1<4.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	dzhu
GH_TAGNAME=	5173b3cf68c9eaaf4b5d7fcb2e6c169c4f56f388
USE_PYTHON=	autoplist concurrent distutils

TEST_TARGET=	test

NO_ARCH=	yes

.include <bsd.port.mk>
