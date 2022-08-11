PORTNAME=	adzap
PORTVERSION=	20110915
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://adzapper.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter out animated ad banners from web pages

LICENSE=	BSD3CLAUSE

USES=		perl5 shebangfix
SHEBANG_FILES=	scripts/squid_redirect-nodata scripts/wrapzap scripts/zapchain
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	adzap.conf pkg-message

PORTDOCS=	index.html update-instructions.txt TODO my-bsd-license.html
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/wrapzap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect-nodata ${STAGEDIR}${PREFIX}/libexec/squid_redirect
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${STAGEDIR}${PREFIX}/libexec/adzap
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/zapchain ${STAGEDIR}${PREFIX}/libexec/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/zaps ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/rc ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/adzap.conf ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
