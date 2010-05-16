# New ports collection makefile for:	sylpheed-claws-newmail
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	newmail
PORTVERSION=	0.0.15
PORTREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Message header summary logging plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

PLIST_FILES=	lib/claws-mail/plugins/newmail.a \
		lib/claws-mail/plugins/newmail.la \
		lib/claws-mail/plugins/newmail.so

.include <bsd.port.mk>
