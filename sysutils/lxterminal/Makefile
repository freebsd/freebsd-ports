# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	lxterminal
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	A lightweight terminal emulator from the LXDE project

LIB_DEPENDS=	vte.9:${PORTSDIR}/x11-toolkits/vte

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAN1=		lxterminal.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
