# New ports collection makefile for:	tcptrace
# Version required:	3.2.5
# Date created:		3 March 1997
# Whom:			fenner
#
# $Id: Makefile,v 1.1.1.1 1997/03/06 02:18:51 asami Exp $
#

DISTNAME=	tcptrace-3.2.5
CATEGORIES=	net
# this site uncompresses the file AND sends it with a .gz suffix
#MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	tcptrace_3.2.5.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

NO_WRKSUBDIR=	yes
ALL_TARGET=	depend tcptrace

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcptrace
.endif

.include <bsd.port.mk>
