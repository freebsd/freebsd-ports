# Created by: Tony Narlock <tony@git-pull.com>
# $FreeBSD$

PORTNAME=	tmuxp
PORTVERSION=	1.5.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Session manager for tmux

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7<8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaptan>=0.5.10:devel/py-kaptan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtmux>=0.8<0.9:devel/py-libtmux@${PY_FLAVOR} \
		tmux:sysutils/tmux

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
