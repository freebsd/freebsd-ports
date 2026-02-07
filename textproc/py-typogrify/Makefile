PORTNAME=	typogrify
PORTVERSION=	2.1.0
CATEGORIES=	textproc
MASTER_SITES=	PYPI \
		https://github.com/justinmayer/typogrify/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Filters to enhance web typography, including support for Django and Jinja templates
WWW=		https://github.com/justinmayer/typogrify

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smartypants>=1.8.3:textproc/py-smartypants@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	typogrify/packages/titlecase/__init__.py

.include <bsd.port.mk>
