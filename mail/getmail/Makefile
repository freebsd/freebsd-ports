# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	4.2.2
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/getmail-4/%SUBDIR%/
MASTER_SITE_SUBDIR=	old-versions

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	POP3/IMAP mail retriever with Maildir and command delivery

USE_PYTHON=	yes
USE_REINPLACE=	yes

SCRIPTS=	getmail getmail_maildir getmail_mbox
MAN1=		getmail.1
DOCS=		CHANGELOG THANKS TODO configuration.txt documentation.txt \
		faq.txt configuration.html documentation.html \
		faq.html troubleshooting.txt troubleshooting.html

do-build:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's!/usr/lib/getmail!${DATADIR}!' \
		-e 's!`which python`!${PYTHON_CMD}!' \
		-e 's!/usr/bin/python!${PYTHON_CMD}!' ${SCRIPTS} *.py

do-install:
	@${MKDIR} ${DATADIR} ${DATADIR}/getmailcore
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${DATADIR}
	@${LN} -s ${DATADIR}/getmail ${PREFIX}/bin/getmail
	@${LN} -s ${DATADIR}/getmail_maildir ${PREFIX}/bin/getmail_maildir
	@${LN} -s ${DATADIR}/getmail_mbox ${PREFIX}/bin/getmail_mbox
	cd ${WRKSRC}/docs && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR} ${DATADIR}/getmailcore
	${INSTALL_SCRIPT} ${WRKSRC}/getmailcore/*.py ${DATADIR}/getmailcore/
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
