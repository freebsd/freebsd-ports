# Created by: Vyacheslav Anikin <anikinsl@gmail.com>
# $FreeBSD$

PORTNAME=	pidgin-osd
PORTVERSION=	0.1.0
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	https://babelize.org/download/pidgin-osd/

MAINTAINER=	anikinsl@gmail.com
COMMENT=	Pidgin plugin for displaying new messages on screen

BROKEN=		unfetchable

BUILD_DEPENDS=	pidgin:net-im/pidgin \
		xosd>=2.2.12:misc/xosd
RUN_DEPENDS=	pidgin:net-im/pidgin \
		xosd>=2.2.12:misc/xosd

USES=		gmake gnome libtool pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-osd.so

.include <bsd.port.mk>
