# Ports collection makefile for:	py-xmpppy
# Date created:				21 April 2006
# Whom:					Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmpppy
PORTVERSION=	0.3.1
CATEGORIES=	net-im python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Python library that provides easy scripting with Jabber

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s.^#!/usr/bin/python.#!${PYTHON_CMD}."

.include <bsd.port.mk>
