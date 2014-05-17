# Created by: Vyacheslav Anikin <anikinsl@gmail.com>
# $FreeBSD$

PORTNAME=	pidgin-osd
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	https://babelize.org/download/pidgin-osd/

MAINTAINER=	anikinsl@gmail.com
COMMENT=	Pidgin plugin for displaying new messages on screen

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
		xosd>=2.2.12:${PORTSDIR}/misc/xosd
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
		xosd>=2.2.12:${PORTSDIR}/misc/xosd

USES=		gmake libtool pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-osd.so

.include <bsd.port.mk>
