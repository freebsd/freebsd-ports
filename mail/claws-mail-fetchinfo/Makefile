# New ports collection makefile for:	sylpheed-claws-fetchinfo
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	fetchinfo
PORTVERSION=	0.4.24
PORTREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Header insertation plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

PLIST_FILES=	lib/claws-mail/plugins/fetchinfo_plugin.a \
	lib/claws-mail/plugins/fetchinfo_plugin.la \
	lib/claws-mail/plugins/fetchinfo_plugin.so \

.include <bsd.port.mk>
