# ex:ts=8
# Ports collection makefile for:  detex
# Date created:			  Mon Feb 17, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	detex
PORTVERSION=	2.7
CATEGORIES=	print
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strips TeX/LaTeX codes from a file

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	#empty

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNO_MALLOC_DECL"
MAN1=		detex.1
PLIST_FILES=	bin/detex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1}l ${MANPREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
