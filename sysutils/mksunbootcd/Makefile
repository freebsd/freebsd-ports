# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	mksunbootcd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	NETBSD

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes ISO images suitable to boot on sparc systems

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

PLIST_FILES=	bin/mksunbootcd man/man1/${PORTNAME}.1.gz

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
