# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getmail
DISTVERSION=	5.14
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/getmail/old-versions/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	POP3/IMAP4 mail retriever with Maildir and command delivery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-31

USES=		python:2.7
USE_PYTHON=	autoplist distutils

CONFLICTS=	py*-getmail6

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	*.css *.html *.txt BUGS CHANGELOG README THANKS TODO
PORTEXAMPLES=	getmailrc-examples

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${CHMOD} -R 644 ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/getmailcore/*

post-install-DOCS-on:
	@${CP} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
