PORTNAME=	gavl
DISTVERSION=	2.0.1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/bplaum/gavl/releases/download/v${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for handling uncompressed video and audio data
WWW=		https://github.com/bplaum/gavl

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle \
		libpng.so:graphics/png \
		libva.so:multimedia/libva

USES=		gl iconv libtool localbase pkgconfig
USE_GL=		egl gl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen
INSTALL_TARGET=	install-strip

PORTDOCS=	README

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e \
		's|-O3 -fomit-frame-pointer||g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
