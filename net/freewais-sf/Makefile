# New ports collection makefile for:	FreeWAIS_sf-2.1.2
# Version required:	 2.1.1
# Date created:		19 November 1996
# Whom:			Pedro Giffuni <pgiffuni@fps.biblos.unal.edu.co>
#
# $Id: Makefile,v 1.3 1997/02/19 05:49:17 asami Exp $
#

DISTNAME=	freeWAIS-sf-2.1.2
PKGNAME=	freewais-sf-2.1.2
CATEGORIES=	net databases
MASTER_SITES=   ftp://ftp.wsct.wsc.com/pub/freeWAIS-sf/freeWAIS-sf-2.1/

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= < ${FILESDIR}/configure.ans
MAN1=	catalog.1 dictionary.1 inverted_file.1 makedb.1 mkfmt.1 waisindex.1 \
	waisq.1 waissearch.1 xwais.1 xwaisq.1
MAN3=	ftw.3 scandir.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SF
	${CP} ${WRKSRC}/doc/SF/fwsf.ps ${PREFIX}/share/doc/SF
.endif

.include <bsd.port.mk>
