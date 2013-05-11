# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	cachesaver
PORTVERSION=	0.10.9
PORTREVISION=	18
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Cache saving plugin for Claws Mail

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.9.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.9.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

DEPRECATED=	No longer maintained by Claws Mail team
EXPIRATION_DATE=2013-06-11

PLIST_FILES=	lib/claws-mail/plugins/cachesaver.a \
		lib/claws-mail/plugins/cachesaver.la \
		lib/claws-mail/plugins/cachesaver.so

.include <bsd.port.mk>
