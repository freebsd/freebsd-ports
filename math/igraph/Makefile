# New ports collection makefile for:	igarph
# Date created:				07 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	igraph
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://cneurocvs.rmki.kfki.hu/igraph/download/

MAINTAINER=	wenheping@gmail.com
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--enable-gmp
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 asm
.endif

.include <bsd.port.post.mk>
