# Created by: fenner
# $FreeBSD$

PORTNAME=	tcptrace
PORTVERSION=	6.6.7
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP dump file analysis tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
ALL_TARGET=	tcptrace

PLIST_FILES=	bin/${PORTNAME} \
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
