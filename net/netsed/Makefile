# Ports collection makefile for:  netsed
# Date created:			  Jan 9 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	netsed
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://dione.ids.pl/~lcamtuf/ \
		http://lcamtuf.na.export.pl/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@oven.org
COMMENT=	Alters the contents of packets in real-time

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netsed ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netsed
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/netsed
.endif

.include <bsd.port.mk>
