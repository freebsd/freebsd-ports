# New ports collection makefile for:	brutecopy
# Date created:		11 Jan 2005
# Whom:			x
#
# $FreeBSD$
#

PORTNAME=	brutecopy
PORTVERSION=	20011229
CATEGORIES=	net
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/clock/bcp/
DISTNAME=	bcp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transferring files over Internet via UDP

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/bcpc bin/bcps
MAN1=		bcp.1
MANCOMPRESSED=	yes

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -Wall -fomit-frame-pointer -falign-functions=0
.endif

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bcps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bcpc ${PREFIX}/bin
	${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bcp.1.gz ${MAN1PREFIX}/man/man1

pre-everything::
.ifndef WITH_OPTIMIZED_CFLAGS
	@${ECHO} "Define WITH_OPTIMIZED_CFLAGS for compiling with -O3"
.endif

.include <bsd.port.mk>
