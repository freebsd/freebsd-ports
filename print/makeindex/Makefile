# New ports collection makefile for:    makeindex
# Date created:         12 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	makeindex
PORTVERSION=	3.0.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.th-darmstadt.de/pub/tex/src/makeindex/BETA/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A general purpose, formatter-independent index processor

WRKSRC=		${WRKDIR}/makeindex
MAN1=		makeindex.1

do-build:
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make)

do-install:
	@${MKDIR} ${PREFIX}/share/texmf/makeindx
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make install)
	@(cd ${WRKSRC}/doc; \
	  ${SED} -e s:/usr/local/lib/tex/macros/:${PREFIX}/share/texmf/makeindx/: \
	      <makeindex.l >makeindex.1; \
	  ${INSTALL_DATA} makeindex.1 ${PREFIX}/man/man1/)

.include <bsd.port.mk>
