# New ports collection makefile for:	sylpheed-claws-etpan_privacy
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	etpan_privacy
PORTVERSION=	0.14
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-
DISTNAME=	etpan-privacy-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	S/MIME, PGP verification and decryption plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=	lib/sylpheed-claws/plugins/etpan-privacy.a \
	lib/sylpheed-claws/plugins/etpan-privacy.la \
	lib/sylpheed-claws/plugins/etpan-privacy.so

.include <bsd.port.mk>
