# New ports collection makefile for:	arla
# Date created:			09 Sep 1998
# Whom:				Peter Hawkins <thepish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arla
PORTVERSION=	0.34.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=	assar@freebsd.org

USE_XLIB=	yes

.if !exists(/usr/lib/libkafs.a)
BROKEN=		requires kerberos
.endif

.if !exists(/usr/src/sys/kern/vnode_if.src)
BROKEN=		requires kernel source
.endif

GNU_CONFIGURE=	yes
MAN3=		cmd.3

.include <bsd.port.mk>
