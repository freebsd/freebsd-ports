# Created by: fenner
# $FreeBSD$

PORTNAME=	tcptrace
PORTVERSION=	6.6.7
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP dump file analysis tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ALL_TARGET=	tcptrace

PLIST_FILES=	bin/${PORTNAME} \
		bin/xpl2gpl

MAN1=		tcptrace.1

PORTDOCS=	ARGS CHANGES FAQ README README.mailing_list \
		README.modules README.tline_graphs README.tput_graphs \
		README.version README.xpl2gpl THANKS dot_tcptracerc

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xpl2gpl ${PREFIX}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${MAN1PREFIX}/man/man1/${PORTNAME}.1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
