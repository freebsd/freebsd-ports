# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shuf
PORTVERSION=	1.8
CATEGORIES=	sysutils
MASTER_SITES=	https://devio.us/~bcallah/shuf/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Randomly permute input lines

LICENSE=	ISCL

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/shuf man/man1/shuf.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shuf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shuf.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
