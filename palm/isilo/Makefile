# New ports collection Makefile for:	isilo
# Version required:	2.53
# Date created:		20 December 1999
# Whom:			nik
#
# $FreeBSD$
#

DISTNAME=	iSilo386
PKGNAME=	isilo-2.53
CATEGORIES=	palm textproc
MASTER_SITES=	ftp://ftp.iSilo.com/pub/

MAINTAINER=	nik@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		iSilo386.1
MANCOMPRESSED=	no

post-extract:
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/iSilo386.1 ${WRKDIR}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
