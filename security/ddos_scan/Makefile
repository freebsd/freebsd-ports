# ex:ts=8
# Ports collection makefile for:  ddos_scan
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ddos_scan
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scans for a limited set of distributed denial of service agents

ALL_TARGET=	dds

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ddos_scan
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/ddos_scan
.endif

.include <bsd.port.mk>
