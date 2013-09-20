# Created by: Mark R V Murray <mark@grondar.za>
# $FreeBSD$

PORTNAME=	par
PORTVERSION=	1.52
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/
DISTNAME=	Par${PORTVERSION:S|.||}

MAINTAINER=	mark@grondar.za
COMMENT=	Paragraph reformatter for email

CONFLICTS=	quake-par-[0-9]*

ALL_TARGET=	#
MAN1=		par.1
PLIST_FILES=	bin/par

NO_STAGE=	yes
do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
