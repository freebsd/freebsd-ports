# Created by: Pankov Pavel <pankov_p@mail.ru>
# $FreeBSD$

PORTNAME=	nullpop
PORTVERSION=	0.3
CATEGORIES=	mail
MASTER_SITES=	http://thewalter.net/stef/software/nullpop/

MAINTAINER=	pankov_p@mail.ru
COMMENT=	POP3 server that allows logins, but never returns any email

BROKEN=		unfetchable

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libexecdir="${PREFIX}/bin"

PLIST_FILES=	bin/nullpop \
		man/man8/nullpop.8.gz

.include <bsd.port.mk>
