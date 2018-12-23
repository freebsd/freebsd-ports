# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bogofilter
PORTREVISION=	0

COMMENT=	Spam filtering plugin for Claws Mail

CLAWS_PLUGINS_BUILD=	bogofilter

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	BDB SQLITE TC
OPTIONS_DEFAULT=	BDB

TC_DESC=		Tokyo Cabinet database support

BDB_RUN_DEPENDS=	bogofilter>0:mail/bogofilter
SQLITE_RUN_DEPENDS=	bogofilter-sqlite>0:mail/bogofilter-sqlite
TC_RUN_DEPENDS=		bogofilter-tc>0:mail/bogofilter-tc

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
