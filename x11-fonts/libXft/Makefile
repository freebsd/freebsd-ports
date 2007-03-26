# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXft
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://xlibs.freedesktop.org/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN3=		Xft.3

#.if defined(WITH_CJK)
#PATCH_SITES=    http://bsdchat.com/dist/firefly-cjk-patchset/ \
#		http://bbs.ilc.edu.tw/~chinsan/ \
#		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
#PATCHFILES+=    cjk-patch-libXft-20050716.diff.gz
#.endif

.include <bsd.port.mk>
