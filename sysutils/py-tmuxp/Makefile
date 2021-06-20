# Created by: Tony Narlock <tony@git-pull.com>

PORTNAME=	tmuxp
PORTVERSION=	1.9.2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Session manager for tmux

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7<8.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaptan>=0.5.10:devel/py-kaptan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtmux>=0.10.1<0.11:devel/py-libtmux@${PY_FLAVOR} \
		tmux:sysutils/tmux

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
