# New ports collection makefile for:	sylpheed-claws-maildir
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	maildir
PORTVERSION=	0.24.4
PORTREVISION?=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Maildir++ plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259
USE_BDB=	yes

CONFIGURE_ENV=	CFLAGS="-I${BDB_INCLUDE_DIR}" \
	LDFLAGS="-l${BDB_LIB_NAME} -L${BDB_LIB_DIR}"

PLIST_FILES=	lib/claws-mail/plugins/maildir.a \
	lib/claws-mail/plugins/maildir.la \
	lib/claws-mail/plugins/maildir.so

.include <bsd.port.mk>
