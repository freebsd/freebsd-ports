# New ports collection makefile for:   pidgin-pidgimpd
# Date created:		21 September 2008
# Whom:			hrkfrd@googlemail.com
#
# $FreeBSD$
#

PORTNAME=	pidgimpd
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	net-im audio
MASTER_SITES=	http://ayeon.org/projects/pidgimpd/
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	PidgiMPD is a Pidgin plugin for monitoring/controlling MPD

LIB_DEPENDS=	purple.6:${PORTSDIR}/net-im/libpurple \
		mpd:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

USE_BZIP2=	yes
USE_GNOME=	pkgconfig gtk20
USE_ICONV=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgimpd.so \
		lib/pidgin/pidgimpd.la

.include <bsd.port.mk>
