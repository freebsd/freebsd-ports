# New ports collection makefile for:    makeindex
# Version required:     3.0.8
# Date created:         12 October 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	makeindex
PKGNAME=	makeindex-3.0.8
CATEGORIES+=	printing
MASTER_SITES=	ftp://achilles.doc.ic.ac.uk/tex/contrib/Schrod/
DISTFILES=	makeindex-3.0.8.tar.Z

MAINTAINER=	jmz@FreeBSD.org

build: configure pre-build
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make)

install:
	@echo "===>  Installing for ${DISTNAME}"
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
