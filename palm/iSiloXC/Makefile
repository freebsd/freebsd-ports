# New ports collection Makefile for:	iSiloXC
# Date created:		17 Aug 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iSiloXC
PORTVERSION=	3.35
CATEGORIES=	palm textproc
MASTER_SITES=	http://www.isilox.com/download/iSiloX/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}BSD

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Converts documents from text/html files or URLs to iSilo format

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		iSiloXC.1
MAN5=		ixl.5
MANCOMPRESSED=	no
PLIST_FILES=	bin/iSiloXC

post-extract:
	@${CP} ${FILESDIR}/iSiloXC.1 ${FILESDIR}/ixl.5 ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iSiloXC ${PREFIX}/bin
	@${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/iSiloXC.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ixl.5 ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
