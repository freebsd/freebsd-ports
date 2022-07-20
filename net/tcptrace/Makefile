PORTNAME=	tcptrace
PORTVERSION=	6.6.8
CATEGORIES=	net
#MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	se@FreeBSD.org
COMMENT=	TCP dump file analysis tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison
GNU_CONFIGURE=	yes
ALL_TARGET=	tcptrace
USE_GITHUB=	yes
GH_ACCOUNT=	blitz
GH_TAGNAME=	508f73a

PLIST_FILES=	bin/tcptrace \
		bin/xpl2gpl \
		man/man1/tcptrace.1.gz

PORTDOCS=	ARGS CHANGES FAQ README README.mailing_list \
		README.modules README.tline_graphs README.tput_graphs \
		README.version README.xpl2gpl THANKS dot_tcptracerc

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xpl2gpl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
