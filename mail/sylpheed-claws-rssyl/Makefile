# New ports collection makefile for:	rssyl
# Date created:				17 December 2005
# Whom:					v.velox@vvelox.net
#
# $FreeBSD$
#

PORTNAME=	rssyl
PORTVERSION=	0.7
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed-claws.net/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	A RSS/Atom plugin for sylheed-claws

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	sylpheed-claws>=2.5:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.5:${PORTSDIR}/mail/sylpheed-claws

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259
USE_GETTEXT=	yes
USE_ICONV=	yes

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
