# New ports collection makefile for:	sylpheed-claws-mailmbox
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	mailmbox
PORTVERSION=	1.12
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Mbox maildir plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/sylpheed-claws/plugins/mailmbox.a \
	lib/sylpheed-claws/plugins/mailmbox.la \
	lib/sylpheed-claws/plugins/mailmbox.so

.include <bsd.port.mk>
