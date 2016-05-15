# Created by: Alfred Perlstein <alfred@freebsd.org>
# $FreeBSD$

PORTNAME=	websocket-client
PORTVERSION=	0.37.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# Newer version is called "websocket_client"
# but to keep compat with old portname we fixup
# "-" to "_" here.
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Websocket client for python

LICENSE=	ISCL

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
