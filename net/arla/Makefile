# New ports collection makefile for:	arla
# Date created:			09 Sep 1998
# Whom:				Peter Hawkins <thepish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arla
PORTVERSION=	0.35.6
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
MAN1=		rxdebug.1 tokens.1 unlog.1 aklog.1 klog.1 fs.1 kalog.1 pts.1 \
		udebug.1
MAN3=		cmd.3
MAN5=		CellServDB.5 DynRootDB.5 ThisCell.5 SuidCells.5
MAN8=		mount_xfs.8 umount_xfs.8 arlad.8 arla-cli.8 vos.8 bos.8

.include <bsd.port.mk>
