# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	c2ps
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A PostScript pretty-printer for C source

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_FILES=	bin/c2ps

MAN1=		c2ps.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c2ps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c2ps.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
