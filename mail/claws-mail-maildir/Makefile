# New ports collection makefile for:	sylpheed-claws-maildir
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	maildir
PORTVERSION=	0.22
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Maildir++ plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259
USE_BDB=	yes

CONFIGURE_ENV=	CFLAGS="-I${BDB_INCLUDE_DIR}" \
	LDFLAGS="-l${BDB_LIB_NAME} -L${BDB_LIB_DIR}"

PLIST_FILES=	lib/sylpheed-claws/plugins/maildir.a \
	lib/sylpheed-claws/plugins/maildir.la \
	lib/sylpheed-claws/plugins/maildir.so

.include <bsd.port.mk>
