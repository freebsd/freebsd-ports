# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	telegram-purple
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Libpurple plugin for Telegram messenger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to link: undefined reference to 'backtrace'
BROKEN_sparc64=		fails to compile: assertion fails

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libwebp.so:graphics/webp \
		libpurple.so:net-im/libpurple \
		libpng.so:graphics/png

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	majn
GH_PROJECT=	tgl:tgl
GH_TAGNAME?=	bec2e6d:tgl
GH_SUBDIR=	tgl:tgl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/telegram-purple.so

.include <bsd.port.mk>
