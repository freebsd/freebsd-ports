# New ports collection Makefile for:	isilo
# Date created:		20 December 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	isilo
PORTVERSION=	2.58
CATEGORIES=	palm textproc
MASTER_SITES=	ftp://ftp.iSilo.com/pub/
DISTNAME=	iSiloBSD

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Converts documents from text/HTML to iSilo format

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		iSiloBSD.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/iSiloBSD

post-extract:
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/iSiloBSD.1 ${WRKDIR}

.include <bsd.port.mk>
