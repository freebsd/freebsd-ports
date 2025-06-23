PORTNAME=	signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	7.58.0
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mikael/signal-desktop/:npm \
		https://registry.npmjs.org/@esbuild/freebsd-arm64/-/:esbuildarm64 \
		https://registry.npmjs.org/@esbuild/freebsd-x64/-/:esbuildx64
DISTFILES=	signal-desktop-${DISTVERSION}-npm-cache.tar.gz:npm \
		freebsd-arm64-${ESBUILD_VERS}.tgz:esbuildarm64 \
		freebsd-x64-${ESBUILD_VERS}.tgz:esbuildx64

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Cross-platform centralized encrypted messaging service
WWW=		https://signal.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	${LOCALBASE}/lib/libringrtc.so:multimedia/ringrtc \
		${LOCALBASE}/lib/libsignal_node.so:net-im/libsignal-node \
		${LOCALBASE}/lib/libsignal_sqlcipher_extension.a:devel/signal-sqlcipher-extension \
		${LOCALBASE}/lib/node_sqlcipher.node:security/node-sqlcipher \
		app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libcups.so:print/cups \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng16.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libsndio.so:audio/sndio \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

USES=		desktop-file-utils gettext-runtime gl gnome jpeg nodejs:20,build pkgconfig ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_PROJECT=	Signal-Desktop

USE_GL=		gbm gl
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst

PACKAGE_ENV=	SIGNAL_ENV=production \
		npm_config_runtime=electron \
		npm_config_target=${ELECTRON_VER_MAJOR} \
		npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers
MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		HOME=${WRKDIR} \
		USE_SYSTEM_APP_BUILDER=true \
		SOURCE_DATE_EPOCH=${_BUILD_DATE} \
		PATH=${WRKSRC}/node_modules/.bin:${LOCALBASE}/bin:${PATH}

# Don't download electron binary distribution on electron node_modules installation
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

ESBUILD_BINARY_PATH=${WRKSRC}/node_modules/.pnpm/@esbuild+freebsd-${ESBUILD_ARCH}@${ESBUILD_VERS}/node_modules/@esbuild/freebsd-${ESBUILD_ARCH}/package/bin/esbuild

_BUILD_DATE=	$$(date +'%s')

ELECTRON_VER_MAJOR=	35
ESBUILD_VERS=		0.24.0
PNPM_VERS=		10.11

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}
ESBUILD_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}
APP_OUT_DIR=	linux-${ARCH:S/aarch64/arm64-/:S/amd64//}unpacked

PLIST_SUB=	NODE_ARCH=${NODE_ARCH} \
		SHARP_ARCH=${ARCH:S/aarch64/arm64v8/:S/amd64/x64/}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
PLIST_SUB+=	NOT_AARCH64="@comment "
.elif ${ARCH} == amd64
PLIST_SUB+=	NOT_AARCH64=""
.endif

do-build:
# electron-builder is stupid and tries to open ${LOCALBASE}/share/electron34/electron with WRITE priv
# copy ${LOCALBASE}/share/electron34 in WRKDIR
# it's needed for the do-install phase, it's here because of this issue
# https://github.com/MikaelUrankar/signal-desktop/issues/6 (I don't know why it fails though)
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
	${ECHO_CMD} store-dir=true >> ${WRKSRC}/.pnpm-store

	${CP} ${FILESDIR}/package-lock.json ${WRKSRC}
	${CP} ${FILESDIR}/pnpm-lock.yaml ${WRKSRC}

	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install --ignore-scripts pnpm@${PNPM_VERS}
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ESBUILD_BINARY_PATH=${ESBUILD_BINARY_PATH} npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers pnpm install --ignore-scripts || ${TRUE}

	# Install libsignal_node.so, libringrtc.so and node_sqlcipher.node binaries in node_modules
	${MKDIR} ${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH} \
		 ${WRKSRC}/node_modules/@signalapp/ringrtc/build/freebsd \
		 ${WRKSRC}/node_modules/@signalapp/sqlcipher/prebuilds/freebsd-${NODE_ARCH}

	${CP} ${LOCALBASE}/lib/libsignal_node.so \
		${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH}/@signalapp+libsignal-client.node
	${CP} ${LOCALBASE}/lib/libringrtc.so \
		${WRKSRC}/node_modules/@signalapp/ringrtc/build/freebsd/libringrtc-${NODE_ARCH}.node
	 ${CP} ${LOCALBASE}/lib/node_sqlcipher.node \
		${WRKSRC}/node_modules/@signalapp/sqlcipher/prebuilds/freebsd-${NODE_ARCH}

	# don't ask me why
	${MKDIR} ${WRKSRC}/node_modules/.pnpm/@esbuild+freebsd-${ESBUILD_ARCH}@${ESBUILD_VERS}/node_modules/@esbuild/freebsd-${ESBUILD_ARCH}
	${TAR} xf ${DISTDIR}/freebsd-${ESBUILD_ARCH}-${ESBUILD_VERS}.tgz -C ${WRKSRC}/node_modules/.pnpm/@esbuild+freebsd-${ESBUILD_ARCH}@${ESBUILD_VERS}/node_modules/@esbuild/freebsd-${ESBUILD_ARCH}

	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ESBUILD_BINARY_PATH=${ESBUILD_BINARY_PATH} npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers pnpm install

	# found in reproducible-builds/docker-entrypoint.sh
	cd ${WRKSRC}/sticker-creator && \
		${SETENV} ${MAKE_ENV} pnpm install
	cd ${WRKSRC}/sticker-creator && \
		${SETENV} ${MAKE_ENV} pnpm run build

	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} pnpm run generate

do-install:
# taken from https://github.com/tagattie/FreeBSD-Electron/blob/master/Mk/Uses/electron.mk#L387
# and editors/vscode
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PACKAGE_ENV} npm run build:electron -- \
			--linux --dir --config.npmRebuild=false \
			--config.electronDist=${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${APP_OUT_DIR} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/images/signal-logo-desktop-linux.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/signal-desktop.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/gen
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${RM} -r ${STAGEDIR}${DATADIR}/resources/completions
	${RLN} ${STAGEDIR}${DATADIR}/signal-desktop ${STAGEDIR}${PREFIX}/bin

	${RM} -r ${STAGEDIR}${DATADIR}/resources/app.asar.unpacked/node_modules/pnpm

create-caches-tarball:
	# do some cleanup first
	${RM} -r ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked

	cd ${WRKDIR} && \
		${TAR} czf signal-desktop-${DISTVERSION}-npm-cache.tar.gz .npm pnpm

.include <bsd.port.post.mk>
