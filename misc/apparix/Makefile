# New ports collection makefile for:    apparix
# Date created:         16 Apr 2006
# Whom:                 Frank Steinborn <steinex@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	apparix
PORTVERSION=	20060105
CATEGORIES=	misc
MASTER_SITES=	http://micans.org/apparix/src/
DISTNAME=	${PORTNAME}-06-005

MAINTAINER=	steinex@gmx.de
COMMENT=	Bookmark directories and apparate inside them

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no

MAN1=		apparix.1
PORTDOCS=	apparix.azm apparix.html apparix.ps
PLIST_FILES=	bin/apparix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
