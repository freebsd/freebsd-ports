# New ports collection makefile for:	Par
# Date created:         6 Aug 1997
# Whom:                 mark@grondar.za
#
# $FreeBSD$
#

PORTNAME=	par
PORTVERSION=	1.52
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/
DISTNAME=	Par${PORTVERSION:S|.||}

MAINTAINER=	mark@grondar.za
COMMENT=	Paragraph reformatter for email

ALL_TARGET=
MAN1=		par.1
PLIST_FILES=	bin/par

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
