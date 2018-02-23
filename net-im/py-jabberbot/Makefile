# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	jabberbot
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	SF/pythonjabberbot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Jabber Bot for Python

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmpppy>0:net-im/py-xmpppy@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,^#!/usr/bin/python,#!${PYTHON_CMD},"

.include <bsd.port.mk>
