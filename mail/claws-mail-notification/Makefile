# New ports collection makefile for:	sylpheed-claws-notification
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	notification
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	notification_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	New/unread mail notification plugin for claws-mail

LIB_DEPENDS=	notify:${PORTSDIR}/devel/libnotify
BUILD_DEPENDS=	claws-mail>=3.0.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.0.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:261

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

PLIST_FILES=	lib/claws-mail/plugins/notification_plugin.a \
		lib/claws-mail/plugins/notification_plugin.la \
		lib/claws-mail/plugins/notification_plugin.so \
		share/locale/ca/LC_MESSAGES/notification_plugin.mo \
		share/locale/cs/LC_MESSAGES/notification_plugin.mo \
		share/locale/hu/LC_MESSAGES/notification_plugin.mo \
		share/locale/pt_BR/LC_MESSAGES/notification_plugin.mo \
		share/locale/zh_CN/LC_MESSAGES/notification_plugin.mo \
		share/locale/fi/LC_MESSAGES/notification_plugin.mo

.include <bsd.port.mk>
