# New ports collection makefile for:	XFree86-PrintServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	PrintServer
PORTVERSION=	4.3.0
PORTREVISION=   1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	X430src-1.tgz \
		X430src-2.tgz \
		X430src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 print server

CONFLICTS=	xorg-printserver-*

PLIST_FILES=		bin/Xprt
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		programs/Xserver

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/programs/Xserver/Xprt ${PREFIX}/bin/Xprt

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
