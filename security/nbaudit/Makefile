# ex:ts=8
# Ports collection makefile for:  nat/nbaudit
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nbaudit
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.auscert.org.au/pub/coast/mirrors/ftp.secnet.com/tools/nat10/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	NT/scanners
DISTNAME=	nat10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetBIOS Auditing Tool / Security Kit

WRKSRC=		${WRKDIR}/${DISTNAME}
MAN1=		nat.1 nbaudit.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nat ${PREFIX}/bin
	@${LN} -f ${PREFIX}/bin/nat ${PREFIX}/bin/nbaudit
	@${INSTALL_SCRIPT} ${FILESDIR}/nbaudition.pl ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/nat.1 ${PREFIX}/man/man1
	@${LN} -f ${PREFIX}/man/man1/nat.1 ${PREFIX}/man/man1/nbaudit.1

.include <bsd.port.mk>
