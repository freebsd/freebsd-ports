# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxtask
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF/lxde/LXTask%20%28task%20manager%29/LXTask%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight desktop-independent task manager

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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

post-install:
	@${ECHO_CMD} ${PKGMESSAGE}

.include <bsd.port.mk>
