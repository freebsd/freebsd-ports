# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXft
PORTVERSION=	2.1.6
CATEGORIES=	x11-fonts
MASTER_SITES=	http://freedesktop.org/~ajax/xlibs-release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN3=		Xft.3

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
IGNORE=	Xft requires Render extension headers/library to build.
.endif

.if defined(WITH_CJK)
PATCH_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/ \
		http://bsdchat.com/dist/firefly-cjk-patchset/
PATCHFILES+=	cjk-patch-libXft-20041115.diff.gz
.endif

.include <bsd.port.post.mk>
