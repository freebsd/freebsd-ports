# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxinput
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXInput%20%28Kbd%20and%20amp_%20mouse%20config%29/LXInput%200.3.2/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Keyboard and mouse config tool from the LXDE project

USES=		iconv gmake pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		lxinput.1

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
