# New ports collection makefile for:	fetchlog
# Date created:		11 August 2003
# Whom:			Alexander Haderer <alexander.haderer@charite.de>
#
# $FreeBSD$
#

PORTNAME=	fetchlog
PORTVERSION=	0.94
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fetchlog

MAINTAINER=	alexander.haderer@charite.de
COMMENT=	Fetch and convert new messages of a logfile

MAN1=		fetchlog.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CHANGES 	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README 	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.Nagios	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.SNMP	${DOCSDIR}
.endif

.include <bsd.port.mk>
