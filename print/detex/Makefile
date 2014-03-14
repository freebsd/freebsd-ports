# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	detex
PORTVERSION=	2.8
CATEGORIES=	print
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strips TeX/LaTeX codes from a file

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNO_MALLOC_DECL -DHAVE_STRING_H"
MAN1=		detex.1
PLIST_FILES=	bin/detex

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1}l ${MANPREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
