# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

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
NO_BUILD=	yes
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	index.html update-instructions.txt TODO my-bsd-license.html
PORTEXAMPLES=	*
SUB_FILES=	adzap.conf pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/wrapzap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect-nodata ${STAGEDIR}${PREFIX}/libexec/squid_redirect
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${STAGEDIR}${PREFIX}/libexec/adzap
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/zapchain ${STAGEDIR}${PREFIX}/libexec/

	${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/zaps ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/rc ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/adzap.conf ${STAGEDIR}${EXAMPLESDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
