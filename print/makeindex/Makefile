# New ports collection makefile for:    makeindex
# Version required:     3.0.8
# Date created:         12 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.6 1995/04/19 19:42:24 jmz Exp $
#

DISTNAME=	makeindex
PKGNAME=	makeindex-3.0.8
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.th-darmstadt.de/pub/tex/src/makeindex/BETA/
DISTFILES=	makeindex-3.0.8.tar.Z

MAINTAINER=	jmz@FreeBSD.org

do-build: 
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make)

do-install: 
	@mkdir -p ${PREFIX}/lib/texmf/makeindx
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make install)
	@(cd ${WRKSRC}/doc; \
	  sed -e s:/usr/local/lib/tex/macros/:${PREFIX}/lib/texmf/makeindx/: \
	      <makeindex.l >makeindex.1; \
	  install -c -m 644 makeindex.1 ${PREFIX}/man/man1/)

.include <bsd.port.mk>
