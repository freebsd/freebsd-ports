# New ports collection makefile for:	sylpheed-claws-notification
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	notification
PORTVERSION=	0.9
PORTREVISION?=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	notification_plugin-${PORTVERSION}
PORTREVISION?=	1

MAINTAINER=	c0rn@o2.pl
COMMENT=	New/unread mail notification plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:261

PLIST_FILES=lib/claws-mail/plugins/notification_plugin.a \
	lib/claws-mail/plugins/notification_plugin.la \
	lib/claws-mail/plugins/notification_plugin.so

.include <bsd.port.mk>
