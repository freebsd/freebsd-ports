# Created by: Michael Johnson <ahze@ahze.net>

PORTNAME=	gavl
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for handling uncompressed video and audio data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen
INSTALL_TARGET=	install-strip

# Opt-in to sched* functions
# https://cgit.freebsd.org/src/commit/?id=90fa9705d5cd29cf11c5dc7319299788dec2546a
CFLAGS+=	-D_WITH_CPU_SET_T
LIBS+=		-lm

PORTDOCS=	README

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS PNG DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_OFF=	--disable-libpng

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e \
		's|-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math||g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
