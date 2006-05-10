# New ports collection makefile for:	sylpheed-claws-att_remover
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	att_remover
PORTVERSION=	1.0.1
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Attachments removing plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/sylpheed-claws/plugins/att_remover.a \
	lib/sylpheed-claws/plugins/att_remover.la \
	lib/sylpheed-claws/plugins/att_remover.so

.include <bsd.port.mk>
