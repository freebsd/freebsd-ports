# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	mksunbootcd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes ISO images suitable to boot on sparc systems

MAN1=		mksunbootcd.1
PLIST_FILES=	bin/mksunbootcd

GNU_CONFIGURE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
