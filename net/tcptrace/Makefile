# New ports collection makefile for:	tcptrace
# Version required:	5.1.0
# Date created:		3 March 1997
# Whom:			fenner
#
# $FreeBSD$
#

DISTNAME=	tcptrace.5.1.0
PKGNAME=	tcptrace-5.1.0
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/5.1.0/

MAINTAINER=	fenner@FreeBSD.ORG

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/tcptrace_5.1.0
ALL_TARGET=	tcptrace

DOCFILES=	ARGS BUGS CHANGES COPYRIGHT FAQ README README.mailing_list \
		README.modules README.tput_graphs WWW

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
