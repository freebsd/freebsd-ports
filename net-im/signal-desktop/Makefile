PORTNAME=	signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	7.20.1
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mikael/signal-desktop/:npm \
		https://build-artifacts.signal.org/desktop/:sqlcipher
DISTFILES=	signal-desktop-${DISTVERSION}-npm-cache.tar.gz:npm \
		${SQLCIPHER}.tar.gz:sqlcipher
# for online build
#DISTFILES=	${SQLCIPHER}.tar.gz:sqlcipher

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Cross-platform centralized encrypted messaging service
WWW=		https://signal.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

EXTRACT_DEPENDS=jq:textproc/jq \
		npm:www/npm-node20
BUILD_DEPENDS=	${LOCALBASE}/lib/libcrypto.a:security/openssl \
		${LOCALBASE}/lib/libringrtc.so:multimedia/ringrtc \
		${LOCALBASE}/lib/libsignal_node.so:net-im/libsignal-node \
		${LOCALBASE}/lib/libsignal_tokenizer.a:devel/signal-fts5-extension \
		app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		jq:textproc/jq \
		npm:www/npm-node20
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
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

USES=		desktop-file-utils gettext-runtime gl gnome jpeg xorg
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_PROJECT=	Signal-Desktop

USE_GL=		gbm gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt pango
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

_BUILD_DATE=	$$(date +'%s')

ELECTRON_VER_MAJOR=	30

SQLCIPHER=	sqlcipher-4.5.5-fts5-fix--3.0.7--0.2.1-ef53ea45ed92b928ecfd33c552d8d405263e86e63dec38e1ec63e1b0193b630b

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}
APP_OUT_DIR=	linux-${ARCH:S/aarch64/arm64-/:S/amd64//}unpacked

PLIST_SUB=	NODE_ARCH=${NODE_ARCH} \
		SHARP_ARCH=${ARCH:S/aarch64/arm64v8/:S/amd64/x64/}

NPM_TIMESTAMP=	1661146515

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
PLIST_SUB+=	NOT_AARCH64="@comment "
.elif ${ARCH} == amd64
PLIST_SUB+=	NOT_AARCH64=""
.endif

post-extract:
	# Update node engine
	${PREFIX}/bin/jq '.engines.node = ""' ${WRKSRC}/package.json > ${WRKSRC}/package.json.tmp.1
	${MV} ${WRKSRC}/package.json.tmp.1 ${WRKSRC}/package.json
	# remove mock-server as it doesn't build and is useless
	${PREFIX}/bin/jq 'del(.devDependencies."@signalapp/mock-server")' ${WRKSRC}/package.json > ${WRKSRC}/package.json.tmp
	${MV} ${WRKSRC}/package.json.tmp ${WRKSRC}/package.json

#	# for online build
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} npm install --ignore-optional --ignore-scripts || ${TRUE}

	# for offline build
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install --ignore-optional --ignore-scripts --offline || ${TRUE}

do-build:
# electron-builder is stupid and tries to open ${LOCALBASE}/share/electron30/electron with WRITE priv
# copy ${LOCALBASE}/share/electron30 in WRKDIR
# it's needed for the do-install phase, it's here because of this issue
# https://github.com/MikaelUrankar/signal-desktop/issues/6 (I don't know why it fails though)
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	# Install libsignal_node.so and libringrtc.so binaries in node_modules
	${MKDIR} ${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH} \
		 ${WRKSRC}/node_modules/@signalapp/ringrtc/build/freebsd
	${CP} ${LOCALBASE}/lib/libsignal_node.so \
		${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH}/@signalapp+libsignal-client.node
	${CP} ${LOCALBASE}/lib/libringrtc.so \
		${WRKSRC}/node_modules/@signalapp/ringrtc/build/freebsd/libringrtc-${NODE_ARCH}.node

	${CP} ${DISTDIR}/${SQLCIPHER}.tar.gz \
		${WRKSRC}/node_modules/@signalapp/better-sqlite3/deps/sqlcipher.tar.gz

	# patch-package can't patch sqlite3 on aarch64, patch the yarn cache instead
	cd ${WRKSRC} && ${PATCH} -s -N -i ${FILESDIR}/sqlite3.gyp.diff

	${CP} ${FILESDIR}/dns-fallback.json ${WRKSRC}/build

	@${RM} -r ${WRKSRC}/node_modules/fs-xattr

#	# online build
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers npm install --ignore-optional
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} npm run generate

	# offline build
	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers npm install --ignore-optional --offline
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm run generate --offline

do-install:
# taken from https://github.com/tagattie/FreeBSD-Electron/blob/master/Mk/Uses/electron.mk#L387
# and editors/vscode
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PACKAGE_ENV} npm run build:electron -- \
			--linux --dir --config.npmRebuild=false \
			--config.electronVersion=${ELECTRON_VER} \
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

# This seems to be only required for Windows:
	${RM} -r ${STAGEDIR}${DATADIR}/resources/app.asar.unpacked/node_modules/@nodert-win10-rs4
	${RM} -r ${STAGEDIR}${DATADIR}/resources/app.asar.unpacked/node_modules/@signalapp/windows-dummy-keystroke

create-caches-tarball:
	# do some cleanup first
	${RM} -r ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked

	cd ${WRKDIR} && \
		${TAR} czf signal-desktop-${DISTVERSION}-npm-cache.tar.gz .npm

.include <bsd.port.post.mk>
