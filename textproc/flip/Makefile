# New ports collection makefile for:	flip
# Date created:		2005-07-01
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	flip
PORTVERSION=	1.19
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	itetcu
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert text file line endings between Unix and DOS formats

NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	bsd
PLIST_FILES=	bin/flip
MAN1=		flip.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flip.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
