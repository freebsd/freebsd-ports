# ex:ts=8
# Ports collection makefile for:  find_ddos
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	find_ddos
PORTVERSION=	4.2
CATEGORIES=	security
MASTER_SITES=	http://ftp.cert.org.tw/tools/Security_Scanner/DDOS/  \
		http://www.fbi.gov/nipc/
DISTNAME=	find_ddos_v42_linux
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@brandelf -t Linux ${WRKSRC}/find_ddos

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/find_ddos ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/find_ddos
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/find_ddos
.endif

.include <bsd.port.mk>
