# New ports collection makefile for:	gtksamba
# Version required:			0.1.2
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/11/17 04:16:27 asami Exp $
#

DISTNAME=	gtksamba-0.1.2
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gtksamba ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gtksamba
.for file in COPYING README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksamba
.endfor
.endif

.include <bsd.port.mk>
