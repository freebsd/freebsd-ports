# New ports collection makefile for:    makeindex
# Version required:     3.0.8
# Date created:         12 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1996/11/17 08:44:51 obrien Exp $
#

DISTNAME=	makeindex-3.0.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.th-darmstadt.de/pub/tex/src/makeindex/BETA/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/makeindex
MAN1=		makeindex.1

do-build: 
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make)

do-install: 
	@${MKDIR} ${PREFIX}/lib/texmf/makeindx
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make install)
	@(cd ${WRKSRC}/doc; \
	  sed -e s:/usr/local/lib/tex/macros/:${PREFIX}/lib/texmf/makeindx/: \
	      <makeindex.l >makeindex.1; \
	  ${INSTALL_DATA} makeindex.1 ${PREFIX}/man/man1/)

.include <bsd.port.mk>
