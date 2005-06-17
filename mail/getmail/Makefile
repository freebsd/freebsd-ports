# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	4.3.11
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/getmail/%SUBDIR%/
MASTER_SITE_SUBDIR=	old-versions

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	POP3/IMAP4 mail retriever with Maildir and command delivery

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

MAN1=		getmail.1 getmail_maildir.1 getmail_mbox.1
DOCS=		../README BUGS CHANGELOG THANKS TODO *.txt *.html *.css

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
