# New ports collection makefile for:  Destroy
# Date created:		2003 March 07
# Whom:			shane@freebsdhackers.net
#
# $FreeBSD$
#

PORTNAME=	destroy
PORTVERSION=	20040415
CATEGORIES=	security
MASTER_SITES=	http://www.freebsdhackers.net/destroy/ \
		http://www.impurity.org/mirrors/destroy/

MAINTAINER=	shane@freebsdhackers.net
COMMENT=	A program to securely destroy files on the hard disk

USE_GMAKE=	yes

MAN1=		destroy.1
PLIST_FILES=	bin/destroy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/destroy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/destroy.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
