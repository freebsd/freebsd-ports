# New ports collection makefile for:	theora
# Date created:				09 februari 2003
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	libtheora
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/ \
		http://distfiles.master.finkmirrors.net/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Theora video codec for the Ogg multimedia streaming system

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHEAD_LIBS}"
CONFIGURE_ARGS+=--disable-sdltest \
		--enable-shared \
		--disable-examples

post-patch:
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,  x86_64),  x86_64|amd64),' ${WRKSRC}/configure

.include <bsd.port.mk>
