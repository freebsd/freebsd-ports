# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	3.2.2
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/getmail-3.0/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old-versions

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	POP3 mail retriever with reliable Maildir/command delivery

USE_PYTHON=	yes
USE_REINPLACE=	yes

SCRIPTS=	getmail getmail_maildir getmail_mbox
MAN1=		getmail.1
DOCS=		CHANGELOG THANKS TODO docs.txt faq.txt getmail.txt \
		docs.html faq.html

do-build:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's!/usr/lib/getmail!${DATADIR}!' \
		-e 's!`which python`!${PYTHON_CMD}!' \
		-e 's!/usr/bin/python!${PYTHON_CMD}!' ${SCRIPTS} *.py

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/getmailrc-example ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
