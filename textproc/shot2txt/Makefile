# New ports collection makefile for:	shot2png
# Date created:				18 May 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	shot2txt
PORTVERSION=	1.0
CATEGORIES=	textproc

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= nik
NO_WRKSUBDIR=	yes

MAINTAINER=	nik@freebsd.org

MAN1=		shot2txt.1
MANCOMPRESSED=	yes

do-install:	
	@cd ${WRKSRC}; ${MAKE} BINDIR=${LOCALBASE}/bin SHAREDIR=${LOCALBASE} install

.include <bsd.port.mk>
