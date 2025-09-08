PORTNAME=	markdown-it-py
PORTVERSION=	4.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	markdown_it_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python port of markdown-it
WWW=		https://markdown-it-py.readthedocs.io/en/latest/ \
		https://github.com/executablebooks/markdown-it-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mdurl>=0.1<1:textproc/py-mdurl@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
