# New ports collection makefile for:	wmpccard
# Date created:			00/02/5
# Whom:				Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpccard
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sra.co.jp/people/m-kasahr/wmpccard/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCcard monitor for FreeBSD + PAO

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_XORG=	x11 xpm
MAN1=		wmpccard.1.gz
NO_MANCOMPRESS=	yes
PLIST_FILES=	bin/wmpccard

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpccard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpccard.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
