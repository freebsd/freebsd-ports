# ex:ts=8
# Ports collection makefile for:  find_ddos
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	find_ddos_v31_linux
PKGNAME=	find_ddos-3.1
CATEGORIES=	security
MASTER_SITES=	http://www.fbi.gov/nipc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

do-build:
	@brandelf -t Linux ${WRKSRC}/find_ddos

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/find_ddos ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/find_ddos
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/find_ddos
.endif

.include <bsd.port.mk>
