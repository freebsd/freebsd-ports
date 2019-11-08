# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
PORTVERSION=	0.7.1
CATEGORIES=	math
MASTER_SITES=	http://igraph.org/nightly/get/c/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LICENSE=	GPLv2

BROKEN_mips64=		fails to link: relocation truncated to fit: R_MIPS_TLS_GD against 'igraph_i_interruption_handler'
BROKEN_sparc64=		fails to compile: uses x86 asm

LIB_DEPENDS=	libgmp.so:math/gmp

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pathfix
USE_GNOME=	libxml2
CONFIGURE_ARGS+=	--enable-gmp
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

.include <bsd.port.mk>
