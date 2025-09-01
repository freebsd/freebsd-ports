PORTNAME=	sniffnet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	2
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

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	GyulyVGC

PORTDOCS=	README.md ROADMAP.md SECURITY.md

OPTIONS_DEFINE=	DOCS

# Enable i386 build for SSE2-capable CPUs
.if ${MACHINE_ARCH} == i386
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
RUSTFLAGS+=	-C target-feature=+sse2
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/packaging/linux/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for size in 8 16 22 24 32 36 42 48 64 72 96 128 160 192 256 384 512 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/packaging/linux/graphics/${PORTNAME}_${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
