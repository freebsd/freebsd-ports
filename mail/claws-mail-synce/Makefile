# New ports collection makefile for:	sylpheed-claws-synce
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	synce
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	synce_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Windows CE addressbook plugin for claws-mail

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259

CONFIGURE_ARGS=	--with-libsynce=${LOCALBASE} \
	--with-librapi2=${LOCALBASE}

PLIST_FILES=	lib/claws-mail/plugins/synce_plugin.a \
	lib/claws-mail/plugins/synce_plugin.la \
	lib/claws-mail/plugins/synce_plugin.so

.include <bsd.port.mk>
