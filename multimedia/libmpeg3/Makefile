# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	libmpeg3
PORTVERSION=	1.8
DISTVERSIONSUFFIX=	-src
CATEGORIES=	multimedia
MASTER_SITES=	SF/heroines/releases/081108

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced editing and manipulation of MPEG streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liba52.so:audio/liba52

USES=		alias gmake tar:bzip2
MAKE_ARGS=	CC="${CC}" USE_CSS=0 OBJDIR="obj" \
		CFLAGS="${CFLAGS} ${CPPFLAGS}" LIBS="${LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	index.html
PLIST_FILES=	${BIN_FILES:S|^|bin/|} ${INC_FILES:S|^|include/|} \
		${LIB_FILES:S|^|lib/|}

BIN_FILES=	mpeg3cat mpeg3dump mpeg3peek mpeg3toc
INC_FILES=	libmpeg3.h mpeg3private.h mpeg3protos.h
LIB_FILES=	libmpeg3.a

CPPFLAGS+=	-I. -I${LOCALBASE}/include/a52dec
LIBS+=		-lm -L${LOCALBASE}/lib -la52 -pthread

NASM?=		${LOCALBASE}/bin/nasm

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	MMX

MMX_BUILD_DEPENDS=	nasm:devel/nasm
MMX_MAKE_ARGS=		USE_MMX=1 NASM="${NASM}"
MMX_CFLAGS=		-DHAVE_MMX
MMX_MAKE_ARGS_OFF=	USE_MMX=0

post-patch:
	@${REINPLACE_CMD} -e 's|^OBJDIR|#OBJDIR|g ; \
		 s|^A52DIR|#A52DIR|g ; \
		 s|^include|#include|g' ${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name '*.[ch]' -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD} -e 's|stdint\.h|sys/types.h|g'

do-install:
.for file in ${BIN_FILES}
	cd ${WRKSRC}/obj && ${INSTALL_PROGRAM} ${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in ${INC_FILES}
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${STAGEDIR}${PREFIX}/include
.endfor
.for file in ${LIB_FILES}
	cd ${WRKSRC}/obj && ${INSTALL_DATA} ${file} ${STAGEDIR}${PREFIX}/lib
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
