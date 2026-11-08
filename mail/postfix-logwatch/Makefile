PORTNAME=	postfix-logwatch
PORTVERSION=	1.40.07
CATEGORIES=	mail
MASTER_SITES=	https://michael.orlitzky.com/code/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postfix MTA log parser
WWW=		https://michael.orlitzky.com/code/postfix-logwatch.xhtml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME}

NO_BUILD=	yes

PORTDOCS=	Bugs Changes README.rst
PORTEXAMPLES=	${PORTNAME}.conf ${PORTNAME}.conf-topn

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@(cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's!/usr/local/etc!${ETCDIR}!' \
		${PORTNAME} ${PORTNAME}.1 README.rst)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
