# New ports collection makefile for:	sylpheed-claws-notification
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	notification
PORTVERSION=	0.1.2
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-
DISTNAME=	notification_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	New/unread mail notification plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=1.9.99:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=1.9.99:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=lib/sylpheed-claws/plugins/notification_plugin.a \
	lib/sylpheed-claws/plugins/notification_plugin.la \
	lib/sylpheed-claws/plugins/notification_plugin.so

.include <bsd.port.mk>
