# New ports collection makefile for:	tcptrace
# Version required:	4.0.2
# Date created:		3 March 1997
# Whom:			fenner
#
# $Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp $
#

DISTNAME=	tcptrace-4.1.3
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/4.1.3/
DISTFILES=	tcptrace.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/tcptrace
ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.modules README.tput_graphs WWW

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
