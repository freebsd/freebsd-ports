# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spook
PORTVERSION=	20050207
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.litech.org/spook/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedded RTP/RTSP/HTTP video streamer

# TODO: FireWire IIDC support (needs libraw1394, libdc1394).
# TODO: Test with Luigi-ified V4L input drivers e.g. pwc, etc.

OPTIONS_DEFINE=	JPEG MPEG4 V4L DOCS
OPTIONS_DEFAULT=	JPEG V4L

MPEG4_DESC=	MPEG4 encoding support
V4L_DESC=	V4L input support

USES=		autoreconf tar:bzip2 gmake
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/spook bin/spookctl etc/spook.conf.dist
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
USES+=			jpeg
CONFIGURE_ARGS+=	--enable-encoder-jpeg
.endif

.if ${PORT_OPTIONS:MMPEG4}
LIB_DEPENDS+=		libxvidcore.so:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--enable-encoder-mpeg4
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=	--enable-input-v4l
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/spook ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spookctl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/spook.conf.dist ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
