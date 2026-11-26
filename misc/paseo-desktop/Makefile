PORTNAME=	paseo
DISTVERSIONPREFIX=	v
.include "${.CURDIR}/../paseo/Makefile.common"
CATEGORIES=	misc
PKGNAMESUFFIX=	-desktop

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Agentic development environment (desktop app)
WWW=		https://paseo.sh/ \
		https://github.com/getpaseo/paseo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	lightningcss, used by the Expo web export, has a FreeBSD binary only for amd64

RUN_DEPENDS=	paseo>=${DISTVERSION}<${DISTVERSION}_99:misc/paseo

USES=		desktop-file-utils electron:44,run nodejs:build,run npm:npm

USE_GITHUB=	yes
GH_ACCOUNT=	getpaseo

NO_ARCH=	yes

NPM_PREFETCH_ARCHS=	${ONLY_FOR_ARCHS}
NPM_FETCH_FLAGS+=	--os=freebsd --cpu=${NPM_NODEJS_ARCH}
# Prune node_modules in pre-fetch, before it is archived.
TARGET_ORDER_OVERRIDE=	290:npm-fetch-node-modules

MAKE_ENV+=	CI=1 \
		EXPO_NO_TELEMETRY=1 \
		EXPO_OFFLINE=1 \
		NODE_OPTIONS=--max-old-space-size=4096 \
		npm_config_update_notifier=false

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	paseo-desktop paseo-desktop.desktop

PLIST_FILES=	bin/paseo-desktop \
		share/applications/paseo-desktop.desktop \
		${ICON_SIZES:@s@share/icons/hicolor/${s}x${s}/apps/paseo-desktop.png@}

# Run-time modules installed with the app; SHARED_MODULES are symbolic
# links into misc/paseo.
DESKTOP_MODULES=	builder-util-runtime electron-log electron-updater
SHARED_MODULES=		@getpaseo ws zod

PATCHED_SOURCES=	daemon/package-paths.ts daemon/runtime-paths.ts \
			features/editor-targets/runtime.ts \
			integrations/cli-install/paths.ts main.ts

ICON_SIZES=	32 64 128 256 512

pre-fetch:
	# Drop non-FreeBSD prebuilt native code.
	@if [ -d ${WRKDIR}/node-modules-cache ]; then \
		cd ${WRKDIR}/node-modules-cache && \
		${RM} -r node_modules/app-builder-bin \
			node_modules/hermes-compiler/hermesc \
			node_modules/react-native-skia-android \
			node_modules/react-native-skia-apple-ios \
			node_modules/react-native-skia-apple-macos \
			node_modules/react-native-skia-apple-tvos \
			packages/website/node_modules && \
		${FIND} node_modules packages/*/node_modules -type d \
			\( -name '*.xcframework' -o -path '*/expo*/prebuilds' \) \
			-prune -exec ${RM} -r {} +; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${PATCHED_SOURCES:S|^|${WRKSRC}/packages/desktop/src/|}

do-build:
	# Upstream's build:desktop, without electron-builder.
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${NPM_CMDNAME} run postinstall
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${NPM_CMDNAME} run build:server
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${NPM_CMDNAME} run build --workspace=@getpaseo/expo-two-way-audio
	@cd ${WRKSRC}/packages/app && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		PASEO_WEB_PLATFORM=electron \
		${WRKSRC}/node_modules/.bin/expo export --platform web
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${NPM_CMDNAME} run build:main --workspace=@getpaseo/desktop

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/app-dist ${STAGEDIR}${DATADIR}/node_modules
	# Electron reads the name, version, and entry point from here.
	${PRINTF} '{\n  "name": "paseo-desktop",\n  "productName": "Paseo",\n  "version": "%s",\n  "main": "dist/main.js",\n  "desktopName": "paseo-desktop.desktop"\n}\n' \
		${DISTVERSION} > ${STAGEDIR}${DATADIR}/package.json
	cd ${WRKSRC}/packages/desktop && ${COPYTREE_SHARE} dist ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/packages/app/dist && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/app-dist
	cd ${WRKSRC}/packages/desktop/assets && \
		${COPYTREE_SHARE} editor-targets ${STAGEDIR}${DATADIR} && \
		${MV} ${STAGEDIR}${DATADIR}/editor-targets \
			${STAGEDIR}${DATADIR}/editor-target-icons
	${INSTALL_DATA} ${WRKSRC}/packages/desktop/assets/icon.png ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${LOCALBASE}/bin/node \
		${FILESDIR}/runtime-modules.mjs packages/desktop ${DESKTOP_MODULES} \
		--exclude @getpaseo/cli @getpaseo/server ${SHARED_MODULES:N@getpaseo} | \
		while read dir; do \
			${MKDIR} ${STAGEDIR}${DATADIR}/$${dir} && \
			${TAR} -cf - -C ${WRKSRC}/$${dir} --exclude ./node_modules . | \
				${TAR} -xf - -C ${STAGEDIR}${DATADIR}/$${dir}; \
		done
	${FIND} ${STAGEDIR}${DATADIR}/dist ${STAGEDIR}${DATADIR}/node_modules \
		-type f \( -name '*.d.ts' -o -name '*.d.mts' -o -name '*.map' \) \
		-delete
.for m in ${SHARED_MODULES}
	${LN} -s ${LOCALBASE}/lib/paseo/node_modules/${m} \
		${STAGEDIR}${DATADIR}/node_modules/${m}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/paseo-desktop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/paseo-desktop.desktop ${STAGEDIR}${DESKTOPDIR}
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
.endfor
.for s in 32 64 128
	${INSTALL_DATA} ${WRKSRC}/packages/desktop/assets/${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/paseo-desktop.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/packages/desktop/assets/128x128@2x.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/paseo-desktop.png
	${INSTALL_DATA} ${WRKSRC}/packages/desktop/assets/icon.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/paseo-desktop.png

# Content-hashed bundles and a computed module list: generate the plist.
post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s ${DATADIR_REL} -not -type d >> ${TMPPLIST}

.include <bsd.port.mk>
