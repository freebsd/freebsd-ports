# New ports collection makefile for:   lxterminal
# Date created:                2010/09/24
# Whom:                        Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lxterminal
PORTVERSION=	0.1.9
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	A lightweight terminal emulator from the LXDE project

LIB_DEPENDS=	vte.9:${PORTSDIR}/x11-toolkits/vte

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAN1=		lxterminal.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
