# New ports collection makefile for:	libmpeg3
# Date created:		06 Feb 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg3
PORTVERSION=	1.7
PORTREVISION=	1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	multimedia
MASTER_SITES=	SF/heroines

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Advanced editing and manipulation of MPEG streams

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		a52.0:${PORTSDIR}/audio/liba52

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NASM?=		${LOCALBASE}/bin/nasm
MAKE_ENV=	NASM=${NASM} INSTALL='${INSTALL}' ARCH=${ARCH} PTHREAD_LIBS=${PTHREAD_LIBS}

PORTDOCS=	index.html
MPEG3_UTILS=	mpeg3cat mpeg3dump mpeg3peek mpeg3toc
PLIST_FILES=	${MPEG3_UTILS:S,^,bin/,} include/libmpeg3.h include/mpeg3private.h \
		include/mpeg3protos.h lib/libmpeg3.a

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD} -e 's|stdint\.h|sys/types.h|g'

do-install:
	${INSTALL_PROGRAM} ${MPEG3_UTILS:S,^,${WRKSRC}/${ARCH}/,} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${ARCH}/libmpeg3.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libmpeg3.h ${WRKSRC}/mpeg3private.h \
		${WRKSRC}/mpeg3protos.h ${PREFIX}/include/
.ifndef (NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
