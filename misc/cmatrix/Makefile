# New ports collection makefile for:	cmatrix
# Version required:			0.98b
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	cmatrix-0.98b
CATEGORIES=	misc
MASTER_SITES=	http://www.plattsburgh.edu/faculty/allegrcr/cmatrix/dist/

MAINTAINER=	andy@icc.surw.chel.su

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cmatrix
.for file in COPYING Changelog README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cmatrix
.endfor
.endif

.include <bsd.port.mk>
