# Ports collection makefile for:  sbd
# Date created:			  2004-07-08
# Whom:				  David Thiel (lx@redundancy.redundancy.org)
#
# $FreeBSD$
#

PORTNAME=	sbd
PORTVERSION=	1.36
CATEGORIES=	net security
MASTER_SITES=	http://tigerteam.se/dl/sbd/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A netcat clone with more features and crypto

ALL_TARGET=	unix

PLIST_FILES=	bin/sbd
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
