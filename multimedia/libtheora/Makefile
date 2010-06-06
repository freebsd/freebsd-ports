# New ports collection makefile for:	theora
# Date created:				09 februari 2003
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	libtheora
PORTVERSION=	1.1.1
PORTREVISION=	2
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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,  x86_64),  x86_64|amd64),; \
		/ac_lib/ s,compat,,' ${WRKSRC}/configure
.if ${ARCH}=="amd64"
	@${REINPLACE_CMD} -e 's|#define OC_X86_ASM|#undef OC_X86_ASM|' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
