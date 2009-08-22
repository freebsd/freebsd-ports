# New ports collection makefile for:	plugdaemon
# Date created:				Thu Jun 24 12:38:31 PDT 2004
# Whom:					David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	plugdaemon
PORTVERSION=	2.5.4
CATEGORIES=	net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Plug proxy daemon, forwards TCP/IP connections

MAN1=		plug.1
PLIST_FILES=	sbin/plug

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/plug

.include <bsd.port.mk>
