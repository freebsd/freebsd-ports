# New ports collection makefile for:	wmpccard
# Date created:			00/02/5
# Whom:				Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpccard
PORTVERSION=	1.3
CATEGORIES=	sysutils misc windowmaker
MASTER_SITES=	http://www.sra.co.jp/people/m-kasahr/wmpccard/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCcard monitor for FreeBSD + PAO

USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=		wmpccard.1.gz
NOMANCOMPRESS=	yes
PLIST_FILES=	bin/wmpccard

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpccard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpccard.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
