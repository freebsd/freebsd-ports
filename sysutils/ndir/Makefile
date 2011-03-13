# New ports collection makefile for:	ndir
# Date created:			Jun 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	ndir
PORTVERSION=	0.8.8
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.Informatik.Uni-Oldenburg.DE/~mw/software/
DISTNAME=	NDir-${PORTVERSION}
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A featureful directory lister

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
ALL_TARGET=	compile
CFLAGS+=	-DNO_THOUSANDS_GROUPING
MAN1=		ndir.1
MLINKS=		ndir.1 lv.1 ndir.1 lw.1

PLIST_FILES=	bin/ndir bin/lw bin/lv

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|-Wall -O2|${CFLAGS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndir ${PREFIX}/bin
	${LN} -sf ndir ${PREFIX}/bin/lw
	${LN} -sf ndir ${PREFIX}/bin/lv
	${INSTALL_MAN} ${WRKSRC}/ndir.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
