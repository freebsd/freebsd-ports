# New ports collection makefile for: libmpeg3
# Date created:		06 Feb 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg3
PORTVERSION=	1.5.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	heroines
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Advanced editing and manipulation of MPEG streams

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/Makefile
	@(${FIND} ${WRKSRC} -name '*.[ch]' \
		| ${XARGS} ${REINPLACE_CMD} -i '' -e 's|stdint\.h|sys\/types\.h|g')
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/a52dec-0.7.3/libao/audio_out_oss.c

do-install:
.for i in mpeg3cat mpeg3dump mpeg3toc
	${INSTALL_PROGRAM} ${WRKSRC}/${MACHINE_ARCH}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/${MACHINE_ARCH}/libmpeg3.a ${PREFIX}/lib
.for i in libmpeg3.h mpeg3private.h
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include
.endfor
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
