# New ports collection makefile for:	pure-sockets
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-sockets
PORTVERSION=	0.6
CATEGORIES=	net

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to the Berkeley socket functions

USE_PURE=	yes

PLIST_FILES=	lib/pure/sockets.pure \
		lib/pure/sockets.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
