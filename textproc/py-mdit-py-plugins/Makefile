PORTNAME=	mdit-py-plugins
PORTVERSION=	0.5.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mdit_py_plugins-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of plugins for markdown-it-py
WWW=		https://github.com/executablebooks/mdit-py-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-it-py>=2.0.0<5.0.0:textproc/py-markdown-it-py@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
