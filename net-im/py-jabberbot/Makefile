# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	jabberbot
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	SF/pythonjabberbot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	A simple Jabber Bot for Python

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmpppy>0:${PORTSDIR}/net-im/py-xmpppy

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,^#!/usr/bin/python,#!${PYTHON_CMD},"

.include <bsd.port.mk>
