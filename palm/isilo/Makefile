# New ports collection Makefile for:	isilo
# Version required:	2.51
# Date created:		20 December 1999
# Whom:			nik
#
# $FreeBSD$
#

DISTNAME=	iSilo386
USE_ZIP=	yes
PKGNAME=	isilo-2.51

CATEGORIES=	palm textproc
MASTER_SITES=	ftp://ftp.iSilo.com/pub/

MAINTAINER=	nik

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MAN1=		iSilo386.1
MANCOMPRESSED=	no

post-extract:
	${CP} files/Makefile files/iSilo386.1 ${WRKDIR}

post-install:
	@${CAT} pkg/MESSAGE

.include <bsd.port.mk>
