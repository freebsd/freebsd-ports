# New ports collection makefile for:	FreeWAIS-sf
# Version required:	 2.2.11
# Date created:		19 November 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

DISTNAME=	freeWAIS-sf-2.2.11
PKGNAME=	freewais-sf-2.2.11
CATEGORIES=	net databases
MASTER_SITES=   ftp://ls6-www.cs.uni-dortmund.de/pub/src/freeWAIS-sf/	\
		ftp://ftp.leo.org/pub/comp/general/infosys/wais/freeWAIS/freeWAIS-sf-2.2/ \
		ftp://ftp.germany.eu.net/pub/infosystems/wais/Unido-LS6/freeWAIS-sf-2.2/

MAINTAINER=	ports@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS= < ${WRKDIR}/configure.ans
INSTALL_TARGET=	install install.man

MAN1=	catalog.1 dictionary.1 inverted_file.1 makedb.1 mkfmt.1 waisindex.1 \
	waisq.1 waissearch.1 xwais.1 xwaisq.1
MAN3=	ftw.3 scandir.3

pre-configure:
	${SED} "s,PREFIX,${PREFIX},g" \
	${FILESDIR}/configure.ans.skel > ${WRKDIR}/configure.ans
	${MKDIR} ${PREFIX}
	${MKDIR} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib
	${MKDIR} ${PREFIX}/man/man1

pre-install:
	${MKDIR} ${PREFIX}/lib/freeWAIS-sf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SF
	${CP} ${WRKSRC}/doc/SF/fwsf.ps ${PREFIX}/share/doc/SF
.endif

.include <bsd.port.mk>
