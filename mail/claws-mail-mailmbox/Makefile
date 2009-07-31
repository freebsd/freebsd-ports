# New ports collection makefile for:	sylpheed-claws-mailmbox
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	mailmbox
PORTVERSION=	1.14.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Mbox maildir plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

PLIST_FILES=	lib/claws-mail/plugins/mailmbox.a \
		lib/claws-mail/plugins/mailmbox.la \
		lib/claws-mail/plugins/mailmbox.so

.include <bsd.port.mk>
