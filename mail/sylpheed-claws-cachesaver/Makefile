# New ports collection makefile for:	sylpheed-claws-cachesaver
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	cachesaver
PORTVERSION=	0.8
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Cache saving plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/sylpheed-claws/plugins/cachesaver.a \
	lib/sylpheed-claws/plugins/cachesaver.la \
	lib/sylpheed-claws/plugins/cachesaver.so

.include <bsd.port.mk>
