PORTNAME=	getmail6
DISTVERSION=	6.21.1
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@michael-bueker.de
COMMENT=	POP3/IMAP4 mail retriever (Python3 fork)
WWW=		https://github.com/getmail6/getmail6/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_FILES=	getmail getmail-gmail-xoauth-tokens getmail_*

NO_ARCH=	yes

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
