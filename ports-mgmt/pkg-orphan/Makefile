# Created by: Victor Semionov <semionov@mail.bg>
# $FreeBSD$

PORTNAME=	pkg-orphan
PORTVERSION=	1.0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF

MAINTAINER=	vsemionov@gmail.com
COMMENT=	Console utility for managing unreferenced FreeBSD packages

DEPRECATED=	Does not support pkgng
EXPIRATION_DATE=	2015-01-06

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	pkg-orphan.pl

PLIST_FILES=	sbin/pkg-orphan \
		man/man1/pkg-orphan.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-orphan.pl ${STAGEDIR}${PREFIX}/sbin/pkg-orphan
	${INSTALL_MAN} ${WRKSRC}/pkg-orphan.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
