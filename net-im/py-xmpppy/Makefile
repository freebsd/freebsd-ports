# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmpppy
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	net-im python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-rc1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}rc1

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Python library that provides easy scripting with Jabber

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.7.1:dns/py-dnspython@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,^#!/usr/bin/python,#!${PYTHON_CMD},"

.include <bsd.port.mk>
