# $FreeBSD$

PORTNAME=	pidgin-hotkeys
PORTVERSION=	0.2.4
PORTREVISION=	19
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Pidgin plugin that allows user to assign global hotkeys

LICENSE=	GPLv2

LIB_DEPENDS=	libpurple.so:net-im/libpurple
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/hotkeys.so

post-patch:
	@${REINPLACE_CMD} -e 's,X11/keysym.h,X11/X.h,' ${WRKSRC}/src/hotkeys.c

.include <bsd.port.mk>
