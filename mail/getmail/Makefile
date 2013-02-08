# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getmail
PORTVERSION=	4.37.0
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/getmail/old-versions/ \
		http://mirrors.closedsrc.org/getmail/

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	POP3/IMAP4 mail retriever with Maildir and command delivery

LICENSE=	GPLv2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

MAN1=		getmail.1 getmail_fetch.1 getmail_maildir.1 getmail_mbox.1
PORTDOCS=	README BUGS CHANGELOG THANKS TODO *.txt *.html *.css

.include <bsd.port.options.mk>

post-install:
	@${CHMOD} -R 644 ${PYTHON_SITELIBDIR}/getmailcore/*
	@${CP} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${docs} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
