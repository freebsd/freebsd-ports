# New ports collection makefile for:    dtach
# Date created:         21 Jun 2004
# Whom:                 bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=		dtach
PORTVERSION=		0.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dtach

MAINTAINER=	bkhl@elektrubadur.se
COMMENT=	A small program that emulates the detach feature of screen

GNU_CONFIGURE=	yes
ALL_TARGET=	dtach

MAN1=		dtach.1
PORTDOCS=	COPYING README dtach.spec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtach ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dtach.1 ${MANPREFIX}/man/man1

.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
