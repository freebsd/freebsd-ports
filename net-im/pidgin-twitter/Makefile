# New ports collection makefile for:    pidgin-twitter
# Date created:                         17 May 2008
# Whom:                                 Junji NAKANISHI <jun-g@daemonfreaks.com>
#
# $FreeBSD$

PORTNAME=	pidgin-twitter
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.honeyplanet.jp/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	A pidgin plugin to help twitting via pidgin

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

USE_GNOME=	pkgconfig glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-twitter.so \
		${DATADIR_REL}/prefs.ui
PLIST_DIRS=	${DATADIR_REL}

.include <bsd.port.mk>
