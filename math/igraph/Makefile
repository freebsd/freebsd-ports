# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
PORTVERSION=	0.5.4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/C%20library/${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GCC=	any
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--enable-gmp
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 asm
.endif

.include <bsd.port.post.mk>
