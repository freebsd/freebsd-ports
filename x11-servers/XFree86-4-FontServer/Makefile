# New ports collection makefile for:	XFree86-FontServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	FontServer
PORTVERSION=	4.3.0
PORTREVISION=	3
CATEGORIES=	x11-servers x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-1.tgz \
		X430src-2.tgz \
		X430src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 font server

CONFLICTS=	xorg-fontserver-*

MAN1=			xfs.1
XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver
XINSTALL_MAN_DIRS=	programs/xfs

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
