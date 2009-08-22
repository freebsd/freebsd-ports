# New ports collection makefile for:	fetchlog
# Date created:		11 August 2003
# Whom:			Alexander Haderer <alexander.haderer@loescap.de>
#
# $FreeBSD$
#

PORTNAME=	fetchlog
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	alexander.haderer@loescap.de
COMMENT=	Fetch and convert new messages of a logfile

MAN1=		fetchlog.1
DOCS=		CHANGES README README.Nagios README.SNMP

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fetchlog ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
