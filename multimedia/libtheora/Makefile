# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	libtheora
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/ \
		http://distfiles.master.finkmirrors.net/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Theora video codec for the Ogg multimedia streaming system

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USES=		libtool:keepla
USE_BZIP2=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="${PTHEAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib
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
