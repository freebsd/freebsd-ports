# Created by: Tony Narlock <tony@git-pull.com>
# $FreeBSD$

PORTNAME=	tmuxp
PORTVERSION=	0.1.12
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tony@git-pull.com
COMMENT=	Session manager for tmux

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=0:${PORTSDIR}/devel/py-argcomplete \
		${PYTHON_PKGNAMEPREFIX}kaptan>=0.5.7:${PORTSDIR}/devel/py-kaptan \
		tmux:${PORTSDIR}/sysutils/tmux

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
