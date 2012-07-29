# New ports collection makefile for:	sylpheed-claws-fetchinfo
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	fetchinfo
PORTVERSION=	0.4.25
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Header insertion plugin for claws-mail

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	lib/claws-mail/plugins/fetchinfo_plugin.a \
	lib/claws-mail/plugins/fetchinfo_plugin.la \
	lib/claws-mail/plugins/fetchinfo_plugin.so \

.include <bsd.port.mk>
