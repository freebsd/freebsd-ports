# New ports collection makefile for:	nenscript
# Date created:		10 November 1999
# Whom:			cjm2
#
# $FreeBSD$
#

PORTNAME=	nenscript
PORTVERSION=	1.13.3
CATEGORIES=	print
MASTER_SITES=	http://www.im.lcs.mit.edu/~magnus/nenscript/

MAINTAINER=	cjm2@altavista.net

USE_BZIP2=	yes

MAKEFILE=	makefile
MAN1=		nenscript.1

pre-fetch:
	@${ECHO_MSG} "To build the Non-US version type:"
	@${ECHO_MSG} "    make NON_US=yes"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenscript ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nenscript.1 ${MANPREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/nenscript
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/nenscript

.include <bsd.port.mk>
