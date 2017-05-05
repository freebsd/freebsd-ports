# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzen
PORTVERSION=	0.7.95
CATEGORIES=	multimedia
MASTER_SITES=	http://mediaarea.net/download/binary/mediainfo/${PORTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ZenLib used by MediaInfo and its library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/../../../License.txt

CONFLICTS_INSTALL=	mediainfo-0.[0-6]* mediainfo-0.7.[0-5]*

CONFIGURE_ARGS=	--enable-shared --enable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix tar:xz

WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/ZenLib/Project/GNU/Library

post-patch:
	@${REINPLACE_CMD} -e '/^ZenLib_LIBS/ s|$$(pwd)[^ ]*|${LOCALBASE}/lib|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -lstdc++||g' ${WRKSRC}/configure ${WRKSRC}/libzen.pc.in
	@${REINPLACE_CMD} -e '1 s|bin/bash|bin/sh|' ${WRKSRC}/libzen-config.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/../../../Source/ZenLib/BitStream_Fast.h ${STAGEDIR}${PREFIX}/include/ZenLib/BitStream_Fast.h

.include <bsd.port.mk>
