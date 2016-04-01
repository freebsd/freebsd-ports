# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	c2ps
PORTVERSION=	4.0
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	PostScript pretty-printer for C source

LIB_DEPENDS=	libpaper.so:print/libpaper

CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/c2ps man/man1/c2ps.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c2ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c2ps.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
