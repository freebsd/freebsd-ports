# $FreeBSD$

PORTNAME=	getmail6
DISTVERSIONPREFIX=	v
DISTVERSION=	6.9
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.bueker@berlin.de
COMMENT=	POP3/IMAP4 mail retriever (Python3 fork)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS=	getmail

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	*.css *.html *.txt BUGS CHANGELOG README THANKS
PORTEXAMPLES=	getmailrc-examples

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${CP} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/getmailrc-examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
