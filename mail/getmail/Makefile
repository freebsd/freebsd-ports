# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getmail
PORTVERSION=	4.53.0
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/getmail/old-versions/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	POP3/IMAP4 mail retriever with Maildir and command delivery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		python:2
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	README BUGS CHANGELOG THANKS TODO *.txt *.html *.css

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${CHMOD} -R 644 ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/getmailcore/*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${CP} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
