# Created by: Victor Semionov <semionov@mail.bg>
# $FreeBSD$

PORTNAME=	pkg-orphan
PORTVERSION=	1.0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF

MAINTAINER=	vsemionov@gmail.com
COMMENT=	A console utility for managing unreferenced FreeBSD packages

NO_BUILD=	yes
USES=		perl5

MAN1=		pkg-orphan.1

PLIST_FILES=	sbin/pkg-orphan

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-orphan.pl ${PREFIX}/sbin/pkg-orphan
	${INSTALL_MAN} ${WRKSRC}/pkg-orphan.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
