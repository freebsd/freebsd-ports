# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Xft
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://pdx.freedesktop.org/software/fontconfig/releases/
DISTNAME=	xft-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN3=		Xft.3

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BROKEN=	Xft requires XFree86 4.x to build.
.endif

.include <bsd.port.post.mk>
