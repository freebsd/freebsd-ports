# New ports collection makefile for:   isearch
# Version required:		1.14
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $Id: Makefile,v 1.2 1997/02/18 10:08:37 obrien Exp $
#

DISTNAME=	Isearch-1.14
PKGNAME=	isearch-1.14	
CATEGORIES=	misc databases
MASTER_SITES=	ftp://ftp.cnidr.org/pub/NIDR.tools/Isearch/

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

GNU_CONFIGURE= yes 

post-install:
	strip ${PREFIX}/bin/Isearch
	strip ${PREFIX}/bin/Iindex
	strip ${PREFIX}/bin/Iutil
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/Isearch
	${INSTALL_MAN} ${WRKSRC}/html/*.html ${PREFIX}/share/doc/Isearch
.endif

.include <bsd.port.mk>
