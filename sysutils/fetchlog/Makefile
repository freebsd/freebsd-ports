# New ports collection makefile for:	fetchlog
# Date created:		11 August 2003
# Whom:			Alexander Haderer <alexander.haderer@charite.de>
#
# $FreeBSD$
#

PORTNAME=	fetchlog
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fetchlog

MAINTAINER=	alexander.haderer@charite.de
COMMENT=	Fetch and convert new messages of a logfile

MAN1=		fetchlog.1
DOCS=		CHANGES README README.Nagios README.SNMP

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
