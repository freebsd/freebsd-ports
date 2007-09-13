# New ports collection makefile for:	XFree86-PrintServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	PrintServer
PORTVERSION=	4.5.0
PORTREVISION=	2
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz \
		XFree86-${PORTVERSION}-src-2.tgz \
		XFree86-${PORTVERSION}-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 print server

CONFLICTS=	xorg-printserver-*

DEPRECATED=	isn't maintained anymore
EXPIRATION_DATE=	2007-12-25

EXTRA_PATCHES=	${.CURDIR}/../../x11-servers/XFree86-4-Server/files/patch-lib_font_bitmap_pcfread.c
PLIST_FILES=		bin/Xprt
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		programs/Xserver

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/programs/Xserver/Xprt ${PREFIX}/bin/Xprt

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE=	is part of XFree86 and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif
.include <bsd.port.post.mk>
