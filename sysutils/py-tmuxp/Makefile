# Created by: Tony Narlock <tony@git-pull.com>
# $FreeBSD$

PORTNAME=	tmuxp
DISTVERSION=	1.3.5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session manager for tmux

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.3:devel/py-colorama@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaptan>=0.5.7:devel/py-kaptan@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtmux>0:devel/py-libtmux@${FLAVOR} \
		tmux:sysutils/tmux

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
