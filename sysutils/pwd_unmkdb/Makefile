# Created by: Matthew Fuller <fullermd@over-yonder.net>

PORTNAME=	pwd_unmkdb
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/pwd_unmkdb/ \
		http://distfiles.over-yonder.net/pwd_unmkdb/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Recover a master.passwd from the hashed database

USES=		tar:xz

PLIST_FILES=	man/man8/pwd_unmkdb.8.gz sbin/pwd_unmkdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwd_unmkdb ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pwd_unmkdb.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
