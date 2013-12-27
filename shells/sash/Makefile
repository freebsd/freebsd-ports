# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sash
PORTVERSION=	3.7
CATEGORIES=	shells
MASTER_SITES=	http://members.tip.net.au/~dbell/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stand-Alone shell combining many common utilities

.if !exists(/usr/include/fs/ntfs/ntfsmount.h)
BROKEN=	Depends on fs/ntfs/ntfsmount.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sash ${STAGEDIR}${PREFIX}/bin/sash
	${INSTALL_MAN} ${WRKSRC}/sash.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/sash.1

.include <bsd.port.mk>
