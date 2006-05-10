# New ports collection makefile for:	sylpheed-claws-newmail
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	newmail
PORTVERSION=	0.0.4
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Message header summary logging plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=lib/sylpheed-claws/plugins/newmail.a \
	lib/sylpheed-claws/plugins/newmail.la \
	lib/sylpheed-claws/plugins/newmail.so

.include <bsd.port.mk>
