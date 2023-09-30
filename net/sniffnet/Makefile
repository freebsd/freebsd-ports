PORTNAME=	sniffnet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	4
CATEGORIES=	net wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Comfortably monitor your Internet traffic
WWW=		https://www.sniffnet.net/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	GyulyVGC

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/packaging/linux/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for size in 8 16 22 24 32 36 42 48 64 72 96 128 160 192 256 384 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/packaging/linux/graphics/${PORTNAME}_${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
