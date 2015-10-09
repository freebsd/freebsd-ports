# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slackclient
PORTVERSION=	0.14
CATEGORIES=	net-im python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Slack.com

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websocket-client>0:${PORTSDIR}/www/py-websocket-client

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
