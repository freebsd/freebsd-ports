PORTNAME=	tmuxp
PORTVERSION=	1.16.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Session manager for tmux
WWW=		https://github.com/tmux-python/tmuxp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtmux>=0.15.8<0.16.0:devel/py-libtmux@${PY_FLAVOR} \
		tmux:sysutils/tmux

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
