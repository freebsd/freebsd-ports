# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXft
PORTVERSION=	2.1.7
CATEGORIES=	x11-fonts
MASTER_SITES=	http://xlibs.freedesktop.org/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN3=		Xft.3

.if defined(WITH_CJK)
PATCH_SITES=	http://bsdchat.com/dist/firefly-cjk-patchset/ \
		http://bbs.ilc.edu.tw/~chinsan/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
PATCHFILES+=	cjk-patch-libXft-20050716.diff.gz
.endif

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
IGNORE=	Xft requires Render extension headers/library to build.
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
