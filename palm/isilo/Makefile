# New ports collection Makefile for:	isilo
# Version required:	2.55
# Date created:		20 December 1999
# Whom:			nik
#
# $FreeBSD$
#

DISTNAME=	iSiloBSD
PKGNAME=	isilo-2.55
CATEGORIES=	palm textproc
MASTER_SITES=	ftp://ftp.iSilo.com/pub/

MAINTAINER=	nik@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		iSiloBSD.1
MANCOMPRESSED=	no

post-extract:
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/iSiloBSD.1 ${WRKDIR}

.include <bsd.port.mk>
