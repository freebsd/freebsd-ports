# New ports collection makefile for:	tcptrace
# Version required:	4.0.2
# Date created:		3 March 1997
# Whom:			fenner
#
# $Id: Makefile,v 1.2 1997/04/30 03:18:07 asami Exp $
#

DISTNAME=	tcptrace-4.0.2
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/4.0.2/
DISTFILES=	tcptrace.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

WRKSRC=		${WRKDIR}/tcptrace
ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
