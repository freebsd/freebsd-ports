# New ports collection makefile for:    xorg-fontserver
# Date created:		10 June 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fontserver
PORTVERSION=	6.7.0
CATEGORIES=	x11-servers
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src2.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font server from X.Org

CONFLICTS=	XFree86-FontServer-*

EXTRA_PATCHES=	${CF_PATCHES}

USE_XLIB=	yes

MAN1=		xfs.1

XBUILD_DIRS=	programs/xfs
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/xfs

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/programs/xfs/config \
		${PREFIX}/lib/X11/fs/config.default

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif
.include <bsd.port.post.mk>
