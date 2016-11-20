# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	telegram-purple
PORTVERSION=	1.3.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Libpurple plugin for Telegram messenger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libwebp.so:graphics/webp

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

USES=		execinfo gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20 libxml2
USE_GCC=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	majn:DEFAULT,tgl vysheng:tlparser
GH_PROJECT=	tgl:tgl tl-parser:tlparser
GH_TAGNAME?=	624cf5a:tgl 36bf190:tlparser

BROKEN_sparc64=	cannot compile: assertion fails

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|/etc/telegram-purple/server.tglpub|${PREFIX}/etc/telegram-purple/server.tglpub|g' \
		 ${WRKSRC}/telegram-purple.c

post-extract:
	@${MV} ${WRKSRC_tgl}/* ${WRKSRC}/tgl
	@${MV} ${WRKSRC_tlparser}/* ${WRKSRC}/tgl/tl-parser

.include <bsd.port.post.mk>
