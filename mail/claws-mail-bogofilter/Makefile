PORTNAME=	bogofilter

COMMENT=	Spam filtering plugin for Claws Mail

CLAWS_PLUGINS_BUILD=	${PORTNAME}

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	BDB SQLITE
OPTIONS_DEFAULT=	BDB

BDB_RUN_DEPENDS=	bogofilter>0:mail/bogofilter
SQLITE_RUN_DEPENDS=	bogofilter-sqlite>0:mail/bogofilter-sqlite

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
