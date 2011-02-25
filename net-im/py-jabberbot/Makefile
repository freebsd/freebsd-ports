# New ports collection makefile for:	py-jabberbot
# Date created:		2010-04-04
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	jabberbot
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://thpinfo.com/2007/python-jabberbot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	A simple Jabber Bot for Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xmpp/auth.py:${PORTSDIR}/net-im/py-xmpppy

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,^#!/usr/bin/python,#!${PYTHON_CMD},"

.include <bsd.port.mk>
