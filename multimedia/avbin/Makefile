# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avbin
PORTVERSION=	7
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	FFmpeg wrapper

LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0

LIBNAME=	libavbin.so.${PORTVERSION}
PLIST_FILES=	lib/${LIBNAME} include/avbin.h
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -shared -Wl,-soname,${LIBNAME} -o ${LIBNAME} \
		src/avbin.c -Iinclude -I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include \
		-DAVBIN_VERSION=${PORTVERSION} -DFFMPEG_REVISION=0 \
		-L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib \
		-lavcodec0 -lavformat0

do-install:
	${INSTALL_DATA} ${WRKSRC}/${LIBNAME} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/avbin.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
