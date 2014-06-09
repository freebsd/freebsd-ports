# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	gavl
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for handling uncompressed video and audio data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen

PORTDOCS=	README

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS PNG
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS PNG
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_OFF=	--disable-libpng

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e \
	's|-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math||g' \
		${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
