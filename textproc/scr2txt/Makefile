# New ports collection makefile for:	scr2txt
# Date created:				18 May 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	scr2txt
PORTVERSION=	1.1
CATEGORIES=	textproc

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= nik
NO_WRKSUBDIR=	yes

MAINTAINER=	nik@freebsd.org
COMMENT=	Converts the output of "vidcontrol -p" to text

MAN1=		scr2txt.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/scr2txt

do-install:	
	@cd ${WRKSRC}; ${MAKE} BINDIR=${LOCALBASE}/bin SHAREDIR=${LOCALBASE} install

.include <bsd.port.mk>
