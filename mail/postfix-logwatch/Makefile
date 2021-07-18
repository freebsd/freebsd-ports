# Created by: Alexander Moisseev <moiseev@mezonplus.ru>

PORTNAME=	postfix-logwatch
PORTVERSION=	1.40.03
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/logreporters/${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postfix MTA log parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	Bugs Changes README
PORTEXAMPLES=	${PORTNAME}.conf ${PORTNAME}.conf-topn

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@(cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's!/usr/local/etc!${ETCDIR}!' \
		${PORTNAME} ${PORTNAME}.1 README)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
