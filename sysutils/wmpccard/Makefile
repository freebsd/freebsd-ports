# New ports collection makefile for:	wmpccard
# Version required:		1.2
# Date created:			00/02/5
# Whom:				Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmpccard-1.2
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.sra.co.jp/people/m-kasahr/wmpccard/src/

MAINTAINER=	taoka@FreeBSD.org

USE_X_PREFIX=	yes
MAN1=		wmpccard.1.gz
NOMANCOMPRESS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpccard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpccard.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
