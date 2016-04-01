# Created by: Paul Traina <pst@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pilot-link
PORTVERSION=	0.12.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	palm comms
MASTER_SITES=	http://downloads.pilot-link.org/ \
		http://miwibox.org/distfiles/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Suite of tools to connect and sync your Palm handheld

LICENSE=	GPLv2

BUILD_DEPENDS=	xsltproc:textproc/libxslt

GNU_CONFIGURE=	yes
CFLAGS+=	-I${WRKSRC}/popt -I${LOCALBASE}/include
CONFIGURE_ARGS+=${ICONV_CONFIGURE_BASE}  --with-included-popt --enable-conduits --enable-xsltproc
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig readline tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PNG THREADS USB
USB_DESC=	Compile with USB via libusb support (READ MANUAL!)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.endif

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=--enable-libusb
LDFLAGS+=	-L${PREFIX}/lib -lusb

.if ! ${PORT_OPTIONS:MTHREADS}
IGNORE=		cannot be built: USB support requires THREADS turned on.  Please reconfigure using 'make config'
.endif
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
CONFIGURE_ARGS+=	--with-libpng=${PREFIX}
.else
CONFIGURE_ARGS+=	--disable-png
.endif

post-patch:
	@${REINPLACE_CMD} '/enable_werror="yes"/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|png_voidp_NULL|NULL|g' \
		-e 's|png_error_ptr_NULL|NULL|g' \
		${WRKSRC}/src/pilot-read-notepad.c \
		${WRKSRC}/src/pilot-read-palmpix.c \
		${WRKSRC}/src/pilot-read-screenshot.c \
		${WRKSRC}/src/pilot-read-veo.c

.include <bsd.port.mk>
