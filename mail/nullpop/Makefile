# New ports collection makefile for:   nullpop
# Date created:                2006-08-13
# Whom:                        Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	nullpop
PORTVERSION=	0.3
CATEGORIES=	mail
MASTER_SITES=	http://memberwebs.com/stef/software/nullpop/

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A POP3 server that allows logins, but never returns any email

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libexecdir="${PREFIX}/bin"

PLIST_FILES=	bin/nullpop
MAN8=		nullpop.8

.include <bsd.port.mk>
