# New ports collection makefile for:	pidgin-manualsize
# Date created:		8 May 2008
# Whom:			Joseph S. Atkinson <jsatkinson@embarqmail.com>
#
# $FreeBSD$
#

PORTNAME=	manualsize
PORTVERSION=	0.0.2
CATEGORIES=	net-im
MASTER_SITES=	http://leapster.org/patches/pidgin/source/ \
		http://autocthonia.net/freebsd/distfiles/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}plugin-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jsatkinson@embarqmail.com
COMMENT=	Plugin to allow manual resizing of Pidgin's message input area

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

PLIST_FILES=	lib/pidgin/manualsize.la \
		lib/pidgin/manualsize.so

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

.include <bsd.port.mk>
