# New ports collection makefile for:	sylpheed-claws-synce
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	synce
PORTVERSION=	0.6
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-
DISTNAME=	synce_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Windows CE addressbook plugin for sylpheed-claws

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.0:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

CONFIGURE_ARGS=	--with-libsynce=${LOCALBASE} \
	--with-librapi2=${LOCALBASE}

PLIST_FILES=	lib/sylpheed-claws/plugins/synce_plugin.a \
	lib/sylpheed-claws/plugins/synce_plugin.la \
	lib/sylpheed-claws/plugins/synce_plugin.so

.include <bsd.port.mk>
