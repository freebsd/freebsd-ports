# New ports collection makefile for:   isearch
# Version required:		1.14
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $Id$
#

DISTNAME=	Isearch-1.14
PKG_NAME=	isearch-1.14	
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cnidr.org/pub/NIDR.tools/Isearch/

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

HAS_CONFIGURE = yes 

post-install:
	strip ${PREFIX}/bin/Isearch
	strip $(PREFIX)/bin/Iindex
	strip $(PREFIX)/bin/Iutil
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${PREFIX}/share/doc/Isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${PREFIX}/share/doc/Isearch
.endif

.include <bsd.port.mk>
