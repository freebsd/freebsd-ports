# New ports collection makefile for:	libmpeg3
# Date created:		06 Feb 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg3
PORTVERSION=	1.8
DISTVERSIONSUFFIX=	-src
CATEGORIES=	multimedia
MASTER_SITES=	SF/heroines/releases/081108

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced editing and manipulation of MPEG streams

LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52

OPTIONS=	MMX "Enable MMX instruction set (i386 only)" off

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" USE_CSS=0 OBJDIR="obj" \
		CFLAGS="${CFLAGS} ${CPPFLAGS}" LIBS="${LDFLAGS}"

PORTDOCS=	index.html
PLIST_FILES=	${BIN_FILES:S|^|bin/|} ${INC_FILES:S|^|include/|} \
		${LIB_FILES:S|^|lib/|}

BIN_FILES=	mpeg3cat mpeg3dump mpeg3peek mpeg3toc
INC_FILES=	libmpeg3.h mpeg3private.h mpeg3protos.h
LIB_FILES=	libmpeg3.a

CPPFLAGS=	-I. -I${LOCALBASE}/include/a52dec ${PTHREAD_CFLAGS}
LDFLAGS=	-lm -L${LOCALBASE}/lib -la52 ${PTHREAD_LIBS}

NASM?=		${LOCALBASE}/bin/nasm

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ARGS+=	USE_MMX=1 NASM="${NASM}"
CFLAGS+=	-DHAVE_MMX
.else
MAKE_ARGS+=	USE_MMX=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^OBJDIR|#OBJDIR|g ; \
		 s|^A52DIR|#A52DIR|g ; \
		 s|^include|#include|g' ${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name '*.[ch]' -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD} -e 's|stdint\.h|sys/types.h|g'

do-install:
.for file in ${BIN_FILES}
	cd ${WRKSRC}/obj && ${INSTALL_PROGRAM} ${file} ${PREFIX}/bin
.endfor
.for file in ${INC_FILES}
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${PREFIX}/include
.endfor
.for file in ${LIB_FILES}
	cd ${WRKSRC}/obj && ${INSTALL_DATA} ${file} ${PREFIX}/lib
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
