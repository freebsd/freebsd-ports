# New ports collection makefile for:	diskusage
# Whom:			maske
# Date created:		23 August 1999
#
# $FreeBSD$
#

PORTNAME=	diskusage
PORTVERSION=	1.01
CATEGORIES=	sysutils
MASTER_SITES=	ftp://freebsd.radioslot.com/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.Org

MAN1=		diskusage.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/diskusage

do-build:
	( cd ${WRKSRC}; ${CXX} -ansi diskusage.cpp -o diskusage )

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/diskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/diskusage.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
