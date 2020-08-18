# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
PORTVERSION=	0.8.2
CATEGORIES=	math

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LICENSE=	GPLv2

BROKEN_mips64=		fails to link: relocation truncated to fit: R_MIPS_TLS_GD against 'igraph_i_interruption_handler'
BROKEN_sparc64=		fails to compile: uses x86 asm

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf bison gmake gnome libtool pathfix
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

pre-configure:
	@${ECHO} ${PORTVERSION} > ${WRKSRC}/IGRAPH_VERSION

.include <bsd.port.mk>
