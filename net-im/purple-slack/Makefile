# $FreeBSD$

PORTNAME=	purple-slack
PORTVERSION=	20180508
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

USE_GITHUB=	yes
GH_ACCOUNT=	dylex
GH_PROJECT=	slack-libpurple
GH_TAGNAME=	0179b2c

PLIST_FILES=	lib/purple-2/libslack.so \
		share/pixmaps/pidgin/protocols/16/slack.png \
		share/pixmaps/pidgin/protocols/22/slack.png \
		share/pixmaps/pidgin/protocols/48/slack.png

MAKE_ARGS=	CC="${CC}" SHELL="${LOCALBASE}/bin/bash"

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/purple-2/libslack.so

.include <bsd.port.mk>
