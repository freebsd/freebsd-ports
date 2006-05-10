# New ports collection makefile for:	sylpheed-claws-smime
# Date created:	23 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	smime
PORTVERSION=	0.5.2
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	S/MIME plugin for sylpheed-claws

LIB_DEPENDS=	gpgme.15:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	sylpheed-claws>=2.1.1:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.1.1:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

PLIST_FILES=lib/sylpheed-claws/plugins/smime.a \
	lib/sylpheed-claws/plugins/smime.la \
	lib/sylpheed-claws/plugins/smime.so

.include <bsd.port.mk>
