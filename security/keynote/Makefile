# New ports collection makefile for:	keynote
# Date created:                         02 September 1999
# Whom:                                 se
#
# $FreeBSD$
#

PORTNAME=	keynote
PORTVERSION=	2.b4
CATEGORIES=	security
MASTER_SITES=	http://www.cis.upenn.edu/~angelos/Code/
DISTNAME=	keynote-2-beta4

MAINTAINER=	se@FreeBSD.org

USE_OPENSSL=	RSA

WRKSRC=		${WRKDIR}/KeyNote-2-beta4

MAN1=		keynote.1
MAN3=		keynote.3
MAN4=		keynote.4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynote ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.3 ${PREFIX}/man/man3/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.4 ${PREFIX}/man/man4/
	${MKDIR} ${PREFIX}/share/doc/keynote/
	${INSTALL_DATA} ${WRKSRC}/doc/keynote-spec ${PREFIX}/share/doc/keynote/
	${INSTALL_DATA} ${WRKSRC}/doc/keynote-spec.nroff ${PREFIX}/share/doc/keynote/

.include <bsd.port.mk>
