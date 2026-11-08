PORTNAME=	cosmic-monitor
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	sysutils

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	System monitor for COSMIC
WWW=		https://github.com/pop-os/cosmic-monitor

# I submitted this patch to fix building for FreeBSD.
# It was merged upstream but I have to apply it manually
# until I bump the COSMIC versions here.
PATCH_SITES=	https://github.com/pop-os/iced/commit/
PATCHFILES=	e03ca50ed8838d3ec8392e32a68ce59634517945.patch
PATCH_DIST_STRIP=	-p1

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo desktop-file-utils gl pkgconfig
USE_GL=		egl
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_TUPLE=	pop-os:iced:39d3c99d1315e9a3db76fa8b32aa91e439c38b32:iced/../${WRKSRC_crate_libcosmic:T}/iced

PATCH_WRKSRC=	${WRKSRC_crate_libcosmic}/iced

PLIST_FILES=	bin/cosmic-monitor \
		share/applications/com.system76.CosmicMonitor.desktop \
		share/metainfo/com.system76.CosmicMonitor.metainfo.xml \
		share/icons/hicolor/16x16/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/24x24/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/32x32/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/48x48/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/64x64/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/128x128/apps/com.system76.CosmicMonitor.svg \
		share/icons/hicolor/256x256/apps/com.system76.CosmicMonitor.svg

# My upstream patch renames linux.rs to unix.rs to better fit what it does.
# Unfortunately, patch doesn't apply the rename so we must do it manually.
post-patch:
	@${MV} \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/linux.rs \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/unix.rs

post-install:
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR} \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicMonitor.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicMonitor.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
.for size in 16x16 24x24 32x32 48x48 64x64 128x128 256x256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} \
		${WRKSRC}/res/icons/hicolor/${size}/apps/com.system76.CosmicMonitor.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
.endfor

.include <bsd.port.mk>
