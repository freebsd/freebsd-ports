# New ports collection makefile for:	manipulate_data
# Date created:				24 Jul 2004
# Whom:					bugghy <bugghy@SAFe-mail.net>
#
# $FreeBSD$
#

PORTNAME=	manipulate_data
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://packetstormsecurity.org/groups/thc/

MAINTAINER=	bugghy@SAFe-mail.net
COMMENT=	Search/extract/write raw data

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/read_data ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/write_data ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/search_data ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/replace_data ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
