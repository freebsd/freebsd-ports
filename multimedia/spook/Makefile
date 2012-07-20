# New ports collection makefile for:	spook
# Date created:		1 Sep 2008
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

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

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_CSTD=	gnu89

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal automake
AUTOMAKE_ARGS=	--add-missing

NOMAN=		defined

SUB_FILES=	pkg-message

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=		jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--enable-encoder-jpeg
.endif

.if ${PORT_OPTIONS:MMPEG4}
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--enable-encoder-mpeg4
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=	--enable-input-v4l
.endif

PLIST_FILES=	bin/spook bin/spookctl etc/spook.conf.dist

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/spook ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spookctl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/spook.conf.dist ${PREFIX}/etc

.include <bsd.port.mk>
