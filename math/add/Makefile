# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	add
PORTVERSION=	20130226
CATEGORIES=	math
MASTER_SITES=	ftp://dickey.his.com/add/
EXTRACT_SUFX=	.tgz

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Full-screen editing calculator

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		add.1
PLIST_FILES=	bin/add %%DATADIR%%/add.hlp
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/add ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/add.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/add.hlp ${DATADIR}

.include <bsd.port.mk>
