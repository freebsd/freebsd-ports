# New ports collection makefile for:   mozplugger
# Date created:        2 June 2005
# Whom:                Loren M. Lang <loren@north-winds.org>
#
# $FreeBSD$
#

PORTNAME=	mozplugger
PORTVERSION=	1.10.2
CATEGORIES=	www
MASTER_SITES=	http://mozplugger.mozdev.org/files/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Framework for loading web content in external viewers

USE_XORG=	x11 xt
MAN7=		mozplugger.7
SUB_FILES=	pkg-message
ALL_TARGET=	freebsd

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
