# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getmail
PORTVERSION=	4.46.0
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/getmail/old-versions/ \
		http://mirrors.closedsrc.org/getmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3/IMAP4 mail retriever with Maildir and command delivery

LICENSE=	GPLv2

USES=		python:2
USE_PYTHON=	distutils

PORTDOCS=	README BUGS CHANGELOG THANKS TODO *.txt *.html *.css

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${CHMOD} -R 644 ${STAGEDIR}${PYTHON_SITELIBDIR}/getmailcore/*
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${STAGEDIR}${EXAMPLESDIR}
	@${CP} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
