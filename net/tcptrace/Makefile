# New ports collection makefile for:	tcptrace
# Date created:		3 March 1997
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	tcptrace
PORTVERSION=	6.3.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	fenner@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=	tcptrace

MAN1=		tcptrace.1

DOCFILES=	ARGS CHANGES COPYING COPYRIGHT FAQ README README.mailing_list \
		README.modules README.tline_graphs README.tput_graphs \
		README.version README.xpl2gpl THANKS WWW \
		dot_tcptracerc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xpl2gpl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
