# New ports collection makefile for:	FreeWAIS_sf-2.1.2
# Version required:	 2.1.1
# Date created:		19 November 1996
# Whom:			Pedro Giffuni
#
# $Id: Makefile,v 1.4 1997/12/24 01:21:15 alex Exp $
#

DISTNAME=	freeWAIS-sf-2.1.2
PKGNAME=	freewais-sf-2.1.2
CATEGORIES=	net databases
MASTER_SITES=   ftp://ftp.wsct.wsc.com/pub/freeWAIS-sf/freeWAIS-sf-2.1/

MAINTAINER=	giffunip@asme.org

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
