# New ports collection makefile for:	netstrain
# Date created:		10 July 2003
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	netstrain
PORTVERSION=	3.0
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Tool to measure practical TCP throughput between two machines

DOC_FILES=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netstrain ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netstraind ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
