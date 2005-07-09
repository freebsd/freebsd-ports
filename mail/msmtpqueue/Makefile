# New ports collection makefile for:	msmtpqueue
# Date created:		2004-06-17
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	msmtpqueue
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Scripts to queue mails with msmtp

RUN_DEPENDS=	msmtp:${PORTSDIR}/mail/msmtp

NO_BUILD=	yes

PLIST_FILES=	bin/msmtp-enqueue.sh bin/msmtp-runqueue.sh
PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/msmtp-enqueue.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/msmtp-runqueue.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
