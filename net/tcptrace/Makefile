# New ports collection makefile for:	tcptrace
# Date created:		3 March 1997
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	tcptrace
PORTVERSION=	5.2.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcptrace.org/download/
DISTNAME=	tcptrace.5.2.1

MAINTAINER=	fenner@FreeBSD.org

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/tcptrace_5.2.1
ALL_TARGET=	tcptrace

MAN1=		tcptrace.1

DOCFILES=	ARGS BUGS CHANGES COPYRIGHT FAQ README README.mailing_list \
		README.modules README.tput_graphs WWW dot_tcptracerc.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
