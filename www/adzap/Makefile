# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adzap
PORTVERSION=	20110915
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://adzapper.sourceforge.net/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Filter out animated ad banners from web pages

LICENSE=	BSD

USES=		perl5
NO_BUILD=	yes
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	index.html update-instructions.txt TODO my-bsd-license.html
PORTEXAMPLES=	*
SUB_FILES=	adzap.conf pkg-message

do-configure:
.for FILE in squid_redirect-nodata wrapzap zapchain
	@${REINPLACE_CMD} -e "s:/usr/bin/perl:${PERL5}:g" \
			-e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/${FILE}
.endfor

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
