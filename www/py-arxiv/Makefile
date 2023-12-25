PORTNAME=	arxiv
PORTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the arXiv API
WWW=		https://github.com/lukasschwab/arxiv.py

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.10:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdoc>=0:devel/py-pdoc@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
