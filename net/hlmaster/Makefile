# New ports collection makefile for:	HL Master
# Date created:				Mon Jul  9 02:40:56 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	hlmaster
PORTVERSION=	0.9.2
CATEGORIES=	net games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

MAKEFILE=	Makefile.bsd

MAN1=		${PORTNAME}.1 ${PORTNAME}.gameserver.1 \
		${PORTNAME}.filter.1 ${PORTNAME}.list.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 \
		${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.list \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/examples/woncomm.lst \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
