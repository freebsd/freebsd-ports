# New ports collection makefile for:	sylpheed-claws-smime
# Date created:	23 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	smime
PORTVERSION=	0.7.6
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	S/MIME plugin for claws-mail

LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	claws-mail>=3.5.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.5.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:261

PLIST_FILES=lib/claws-mail/plugins/smime.a \
	lib/claws-mail/plugins/smime.la \
	lib/claws-mail/plugins/smime.so \
	lib/claws-mail/plugins/smime.deps

.include <bsd.port.mk>
