# New ports collection makefile for:	mjpegtools-yuvfilters
# Date created:		2005-04-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mjpegtools-yuvfilters
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://silicontrip.net/~mark/lavtools/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
DISTFILES=	${CFILES:S/$/.c/}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Mjpeg-tools YUV video stream processing tools

LIB_DEPENDS=	lavjpeg-1.6.3:${PORTSDIR}/multimedia/mjpegtools

CFILES=		yuvafps yuvfade yuvwater
PLIST_FILES=	${CFILES:S|^|bin/|}

CPPFLAGS=	-I${LOCALBASE}/include/mjpegtools -DHAVE_INTTYPES_H
LDFLAGS=	-L${LOCALBASE}/lib -lmjpegutils

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${CFILES:S/$/.c/}
	@${CP} -f ${DISTDIR}/${f} ${WRKSRC}
.endfor

do-build:
.for f in ${CFILES}
	${CC} ${WRKSRC}/${f}.c ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/${f}
.endfor

do-install:
.for f in ${CFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
