# New ports collection makefile for:	cmatrix
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cmatrix
PORTVERSION=	1.1b
CATEGORIES=	misc
MASTER_SITES=	http://www.asty.org/cmatrix/dist/

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

MAN1=		cmatrix.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cmatrix
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cmatrix
.endfor
.endif

.include <bsd.port.mk>
