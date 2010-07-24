# New ports collection makefile for:	avbin
# Date created:		03 Apr 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avbin
PORTVERSION=	7
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	FFmpeg wrapper

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

LIBNAME=	libavbin.so.${PORTVERSION}
PLIST_FILES=	lib/${LIBNAME} include/avbin.h
USE_LDCONFIG=	yes

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -shared -soname ${LIBNAME} -o ${LIBNAME} \
		src/avbin.c -Iinclude -I${LOCALBASE}/include \
		-DAVBIN_VERSION=${PORTVERSION} -DFFMPEG_REVISION=0 \
		-L${LOCALBASE}/lib -lavcodec -lavformat

do-install:
	${INSTALL_DATA} ${WRKSRC}/${LIBNAME} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/avbin.h ${PREFIX}/include

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
