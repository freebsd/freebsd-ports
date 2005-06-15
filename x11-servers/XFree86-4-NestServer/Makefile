# New ports collection makefile for:	XFree86-NestServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	NestServer
PORTVERSION=	4.5.0
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz \
		XFree86-${PORTVERSION}-src-2.tgz \
		XFree86-${PORTVERSION}-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 nested X server

CONFLICTS=	xorg-nestserver-[0-9]*

MAN1=			Xnest.1
PLIST_FILES=		bin/Xnest

XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver/hw/xnest

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
