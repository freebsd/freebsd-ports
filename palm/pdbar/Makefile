# New ports collection makefile for:	pdbar
# Date created:		5 January 2004
# Whom:			Eric P. Scott <eps+pdbar@ana.com>
#
# $FreeBSD$
#

PORTNAME=	pdbar
PORTVERSION=	00.05.01
CATEGORIES=	palm
MASTER_SITES=	http://www.djw.org/product/palm/par/
DISTNAME=	prc
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create and manipulate PalmOS database files

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="" AR=${AR} RANLIB=${RANLIB} LD=${CC}

MAN1=		pdbar.1
PLIST_FILES=	bin/pdbar

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/pdbar
		${INSTALL_MAN} ${WRKSRC}/par.man ${MANPREFIX}/man/man1/pdbar.1

.include <bsd.port.mk>
