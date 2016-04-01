# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	telegram-purple
PORTVERSION=	05222015
CATEGORIES=	net-im
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Libpurple plugin for Telegram messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		execinfo gmake pkgconfig tar:xz
USE_GNOME=	glib20 libxml2
USE_GCC=	yes
GNU_CONFIGURE=	yes

BROKEN_sparc64=	cannot compile: assertion fails

pre-configure:
	@${REINPLACE_CMD} -e 's|/etc/telegram-purple/server.pub|${PREFIX}/etc/telegram-purple/server.pub|g' \
		 ${WRKSRC}/telegram-purple.c

.include <bsd.port.mk>
