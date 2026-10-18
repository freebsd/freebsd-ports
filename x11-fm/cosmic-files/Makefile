PORTNAME=	cosmic-files
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	x11-fm

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	File manager for the COSMIC desktop environment
WWW=		https://github.com/pop-os/cosmic-files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	cosmic-icons>=${PORTVERSION}:x11-themes/cosmic-icons \
		xdg-open:devel/xdg-utils

USES=		cargo desktop-file-utils gl pkgconfig
USE_GL=		egl
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_TUPLE=	pop-os:iced:39d3c99d1315e9a3db76fa8b32aa91e439c38b32:iced/../${WRKSRC_crate_libcosmic:T}/iced

# I submitted this patch to fix building for FreeBSD.
# It was merged upstream but I have to apply it manually
# until the next COSMIC version is released.
PATCH_SITES=	https://github.com/pop-os/iced/commit/
PATCHFILES=	e03ca50ed8838d3ec8392e32a68ce59634517945.patch
PATCH_DIST_STRIP=	-p1
PATCH_WRKSRC=	${WRKSRC_crate_libcosmic}/iced

# My upstream patch renames linux.rs to unix.rs to better fit what it does.
# Unfortunately, patch doesn't apply the rename so we must do it manually.
post-patch:
	@${MV} \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/linux.rs \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/unix.rs

# Disable io_uring but enable the rest of the default features
CARGO_FEATURES=	--no-default-features \
		bzip2 dbus-config desktop lzma-rust2 wayland wgpu

PLIST_FILES=	bin/cosmic-files \
		share/applications/com.system76.CosmicFiles.desktop \
		share/metainfo/com.system76.CosmicFiles.metainfo.xml \
		share/icons/hicolor/16x16/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/24x24/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/32x32/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/48x48/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/64x64/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/128x128/apps/com.system76.CosmicFiles.svg \
		share/icons/hicolor/256x256/apps/com.system76.CosmicFiles.svg

OPTIONS_DEFINE=	GVFS NOTIFY
OPTIONS_DEFAULT=	GVFS NOTIFY

GVFS_VARS=	CARGO_FEATURES+=gvfs
NOTIFY_VARS=	CARGO_FEATURES+=notify

GVFS_USES=	gnome
GVFS_USE=	GNOME=glib20,gvfs

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/metainfo

	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicFiles.desktop \
		${STAGEDIR}${PREFIX}/share/applications

	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicFiles.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.for size in 16x16 24x24 32x32 48x48 64x64 128x128 256x256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} \
		${WRKSRC}/res/icons/hicolor/${size}/apps/com.system76.CosmicFiles.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
.endfor

.include <bsd.port.mk>
