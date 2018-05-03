# Created by: Alfred Perlstein <alfred@freebsd.org>
# $FreeBSD$

PORTNAME=	websocket-client
PORTVERSION=	0.45.0
PORTREVISION=	1
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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.ssl_match_hostname>0:security/py-backports.ssl_match_hostname@${FLAVOR}
.endif

.include <bsd.port.post.mk>
