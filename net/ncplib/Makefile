# New ports collection makefile for:	ncplib
# Date created:		9 Dec 1999
# Whom:			Boris Popov <bp@butya.kz>
#
# $FreeBSD$
#

PORTNAME=	ncplib
PORTVERSION=	1.3.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.butya.kz/pub/nwlib/

MAINTAINER=	bp@butya.kz
COMMENT=	Client for Novell NetWare servers

.if !exists(/usr/src/sys/kern/vnode_if.src)
IGNORE=		requires kernel source
.endif

IS_INTERACTIVE=	true

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 310000
.error this program requires FreeBSD 3.1-stable or later.
.endif

MAN1=	ncpasswd.1 ncprint.1 ncpsend.1 ncpurge.1
MAN8=	ipxping.8

.if ${OSVERSION} >= 400000
PLIST=	${PKGDIR}/pkg-plist.4
.else
MAN1+=	ncplist.1 ncplogin.1 ncplogout.1
MAN8+=	mount_nwfs.8
.endif

.include <bsd.port.post.mk>
