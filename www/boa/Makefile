# New ports collection makefile for:	boa
# Version required:			0.92
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	boa-0.92
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	andy@icc.surw.chel.su

do-build:
	@ cd ${WRKSRC}/src; make

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${PREFIX}/sbin
	@ ${MKDIR} ${PREFIX}/share/examples/boa
	@ ${INSTALL_DATA} ${WRKSRC}/conf/* ${PREFIX}/share/examples/boa
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/boa
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/boa
.for file in Changelog Gnu_License biblio.html details.html details.txt logos.html newboa7.gif poweredbyboa.gif readme.html readme.txt todo.txt
	@ ${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/boa
.endfor
.endif

.include <bsd.port.mk>
