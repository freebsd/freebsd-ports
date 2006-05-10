# New ports collection makefile for:	sylpheed-claws-fetchinfo
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	fetchinfo
PORTVERSION=	0.4.13
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Header insertation plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/sylpheed-claws/plugins/fetchinfo_plugin.a \
	lib/sylpheed-claws/plugins/fetchinfo_plugin.la \
	lib/sylpheed-claws/plugins/fetchinfo_plugin.so \
	lib/sylpheed-claws/plugins/fetchinfo_plugin_gtk.a \
	lib/sylpheed-claws/plugins/fetchinfo_plugin_gtk.la \
	lib/sylpheed-claws/plugins/fetchinfo_plugin_gtk.so \
	lib/sylpheed-claws/plugins/fetchinfo_plugin_gtk.deps

.include <bsd.port.mk>
