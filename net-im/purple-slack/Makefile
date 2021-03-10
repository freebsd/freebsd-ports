# $FreeBSD$

PORTNAME=	purple-slack
PORTVERSION=	20210301
CATEGORIES=	net-im

MAINTAINER=	aou@eecs.berkeley.edu
COMMENT=	Slack plugin for libpurple

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple
BUILD_DEPENDS=	bash:shells/bash

USES=		gmake gnome pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" SHELL="${LOCALBASE}/bin/bash"

USE_GITHUB=	yes
GH_ACCOUNT=	dylex
GH_PROJECT=	slack-libpurple
GH_TAGNAME=	f851698

PLIST_FILES=	lib/purple-2/libslack.so \
		share/pixmaps/pidgin/protocols/16/slack.png \
		share/pixmaps/pidgin/protocols/22/slack.png \
		share/pixmaps/pidgin/protocols/48/slack.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/purple-2/libslack.so

.include <bsd.port.mk>
