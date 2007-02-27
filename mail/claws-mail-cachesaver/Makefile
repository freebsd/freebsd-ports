# New ports collection makefile for:	sylpheed-claws-cachesaver
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	cachesaver
PORTVERSION=	0.10.4
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Cache saving plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/claws-mail/plugins/cachesaver.a \
	lib/claws-mail/plugins/cachesaver.la \
	lib/claws-mail/plugins/cachesaver.so

.include <bsd.port.mk>
