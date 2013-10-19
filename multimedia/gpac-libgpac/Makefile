# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpac
PORTVERSION=	0.4.5
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/GPAC/GPAC%20${PORTVERSION}
PKGNAMESUFFIX=	-libgpac

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gpac MPEG-4 Systems library and headers

WRKSRC=		${WRKDIR}/gpac
ALL_TARGET=	lib
USES=		gmake
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/bin/gcc
LIBVER=	1

OPTIONS_DEFINE=	IPV6 JPEG OPENGL SSL PNG XVIDEO
OPTIONS_DEFAULT=	IPV6 JPEG SSL PNG

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--cc="${CC}" --X11-path="${LOCALBASE}" \
		--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}" \
		--enable-pic \
		--disable-wx \
		--use-js=no --use-a52=no --use-faad=no --use-ffmpeg=no \
		--use-ft=no --use-mad=no --use-ogg=no \
		--use-openjpeg=no --use-theora=no --usr-vorbis=no

CONFIGURE_ENV+=	LIBVER="${LIBVER}" PTHREAD_LIBS="${PTHREAD_LIBS}"

SSL_USE=	OPENSSL=yes
SSL_CONFIGURE_ENABLE=	ssl
OPENGL_USE=	GL=gl GL=glu
OPENGL_CONFIGURE_ENABLE=	opengl
XVIDEO_LIB_DEPENDS=	libXv.so:${PORTSDIR}/x11/libXv
XVIDEO_CONFIGURE_OFF=	--disable-x11-xv --disable-x11-shm
IPV6_CONFIGURE_ENABLE=	ipv6
JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
JPEG_CONFIGURE_ON=	--use-jpeg=local
JPEG_CONFIGURE_OFF=	--use-jpeg=no
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ON=	--use-png=local
PNG_CONFIGURE_OFF=	--use-png=no
PNG_CFLAGS=		-I${LOCALBASE}/include/libpng15

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gpac
	cd ${WRKSRC}/include/gpac && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${PREFIX}/include/gpac
	${INSTALL_LIB} ${INSTALL_WRKSRC}/libgpac.so.${LIBVER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libgpac.so.${LIBVER} ${STAGEDIR}${PREFIX}/lib/libgpac.so
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libgpac_static.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
