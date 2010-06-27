# New ports collection makefile for:	fetchlog
# Date created:		11 August 2003
# Whom:			Alexander Haderer <alexander.haderer@loescap.de>
#
# $FreeBSD$
#

PORTNAME=	fetchlog
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	alexander.haderer@loescap.de
COMMENT=	Fetch and convert new messages of a logfile

MAN1=		fetchlog.1
PORTDOCS=	CHANGES README README.Nagios README.SNMP
PORTEXAMPLES=	fetchlog.cfg fetchlog_service.cfg notify.cfg.example

PLIST_FILES=	bin/fetchlog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fetchlog ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
