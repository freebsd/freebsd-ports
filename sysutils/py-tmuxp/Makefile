PORTNAME=	tmuxp
PORTVERSION=	1.28.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Session manager for tmux
WWW=		https://github.com/tmux-python/tmuxp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtmux>=0.22.1<0.23:devel/py-libtmux@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=6.0<7:devel/py-yaml@${PY_FLAVOR} \
		tmux:sysutils/tmux

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
