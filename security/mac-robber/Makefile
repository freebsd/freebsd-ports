# Ports collection makefile for:  mac-robber
# Date created:			  Jan 12 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mac-robber
PORTVERSION=	1.00
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	A tool for listing Modify, Access, Create timestamps from files

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o mac-robber mac-robber.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${PREFIX}/bin

.include <bsd.port.mk>
