# New ports collection makefile for:	sylpheed-claws-etpan_privacy
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	etpan_privacy
PORTVERSION=	0.15.4
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	etpan-privacy-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	S/MIME, PGP verification and decryption plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/claws-mail/plugins/etpan-privacy.a \
	lib/claws-mail/plugins/etpan-privacy.la \
	lib/claws-mail/plugins/etpan-privacy.so

.include <bsd.port.mk>
