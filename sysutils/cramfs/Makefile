# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cramfs
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	gslin@gslin.org
COMMENT=	The compressed ROM filesystem

MAKEFILE=	GNUmakefile
USE_GMAKE=	yes

PLIST_FILES=	sbin/cramfsck sbin/mkcramfs

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cramfsck ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mkcramfs ${PREFIX}/sbin

.include <bsd.port.mk>
