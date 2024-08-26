PORTNAME=	tor-browser
DISTVERSION=	13.5a9
PORTREVISION=	2
CATEGORIES=	www net security wayland
MASTER_SITES=	TOR \
		https://build-sources.tbb.torproject.org/:source1 \
		LOCAL/jsm:source2
MASTER_SITE_SUBDIR=	torbrowser/${DISTVERSION}
DISTNAME=	src-firefox-tor-browser-115.12.0esr-13.5-1-build2
DISTFILES=	${DISTNAME}.tar.xz \
		manual_112141.zip:source1 \
		firefox-tor-browser-13.0.1-build2-firefox-1l0n-out.tar:source2
MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tor Browser for FreeBSD
WWW=		https://www.torproject.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.94:security/nss \
		icu>=73.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=8.2.2:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.39:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.13.1:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip
USE_GITLAB=nodefault
GL_SITE=	https://gitlab.torproject.org/
GL_ACCOUNT=	tpo
GL_PROJECT=	translation:basebrowser translation:torbrowser
GL_TAGNAME=	3faf7dcd545109f7bbd8a6374838e139ca422d6c:basebrowser 51bc08246d73990d461f747fb3c8cc7b6f66c1f4:torbrowser
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor

USES=		compiler:c++11-lib libtool \
		perl5 pkgconfig python shebangfix localbase:ldflags tar:xz python:3
USE_GECKO=	gecko

SSP_UNSAFE=	yes

SUB_FILES=	torrc-defaults tor-browser.desktop
BUNDLE_LIBS=	yes

USE_MOZILLA=	-sqlite
MOZILLA_VER=115.4.0
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_CHROME_MULTILOCALE="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW en-US"
MAKE_ENV+=	AB_CD="multi" \
		LOCALES="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW en-US"
MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Tor Browser" \
		MOZ_APP_NAME="tor-browser" \
		MOZ_CHROME_MULTILOCALE="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW en-US"
MOZ_OPTIONS=	--with-base-browser-version=${DISTVERSION} \
	--enable-official-branding \
	--enable-optimize \
	--enable-bundled-fonts \
	--disable-tests \
	--disable-debug \
	--disable-crashreporter \
	--disable-webrtc \
	--disable-parental-controls \
	--enable-proxy-bypass-protection \
	--disable-system-policies \
	--disable-backgroundtasks \
	--with-distribution-id=org.torproject \
	--with-branding=browser/branding/tb-release

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
SHEBANG_FILES+=	mach
.include	"${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

.if ${ARCH} == amd64
MOZ_OPTIONS+=	--enable-rust-simd
.endif
.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZILLA_PLIST_DIRS=	bin lib share/pixmaps share/applications share/tor-browser
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif
post-patch:
	@${REINPLACE_CMD} 's|LOCALBASE|${LOCALBASE}|g' "${WRKSRC}/browser/app/profile/000-tor-browser.js"
	${MKDIR} ${WRKSRC}/tmp-manual
	unzip -d ${WRKSRC}/tmp-manual ${DISTDIR}/manual_112141.zip
	${MKDIR} ${WRKSRC}/tmp-l10n-central
	tar -C ${WRKSRC}/tmp-l10n-central -xf ${DISTDIR}/firefox-tor-browser-13.0.1-build2-firefox-1l0n-out.tar
pre-configure:
	@${REINPLACE_CMD} 's|export MOZ_GOOGLE_.*||g' ${WRKSRC}/.mozconfig
	${PYTHON_CMD} ${FILESDIR}/packagemanual.py ${WRKSRC}/tmp-manual/public ${WRKSRC}/browser/base/content/manual
post-build:
	${MKDIR} -p ${WRKSRC}/../.mozbuild/l10n-central
	find  ${WRKSRC}/tmp-l10n-central -name "*.tar.xz"  -exec tar -C ${WRKSRC}/../.mozbuild/l10n-central -xvf {} \;
	cd ${WRKSRC}/../.build/ && MOZBUILD_STATE_PATH=${WRKSRC}/../.mozbuild MOZ_AUTOMATION="1" ${WRKSRC}/mach package-multi-locale  --locales ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW
.for i in ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW
	${CP} ${WRKDIR}/translation-3faf7dcd545109f7bbd8a6374838e139ca422d6c/${i}/base-browser.ftl ${WRKDIR}/.build/dist/bin/browser/localization/${i}/browser/base-browser.ftl
	${CP} ${WRKDIR}/translation-3faf7dcd545109f7bbd8a6374838e139ca422d6c/${i}/newIdentity.properties ${WRKDIR}/.build/dist/bin/browser/chrome/${i}/locale/browser/newIdentity.properties
	${CP} ${WRKDIR}/translation-3faf7dcd545109f7bbd8a6374838e139ca422d6c/${i}/securityLevel.properties ${WRKDIR}/.build/dist/bin/browser/chrome/${i}/locale/browser/securityLevel.properties
	${MKDIR} ${WRKDIR}/.build/dist/bin/chrome/torbutton/locale/${i}/browser
	test -f ${WRKDIR}/translation-51bc08246d73990d461f747fb3c8cc7b6f66c1f4/${i}/tor-browser.ftl && ${CP} ${WRKDIR}/translation-51bc08246d73990d461f747fb3c8cc7b6f66c1f4/${i}/tor-browser.ftl ${WRKDIR}/.build/dist/bin/browser/localization/${i}/browser/tor-browser.ftl 
	${CP} ${WRKDIR}/translation-51bc08246d73990d461f747fb3c8cc7b6f66c1f4/${i}/cryptoSafetyPrompt.properties ${WRKDIR}/.build/dist/bin/browser/chrome/${i}/locale/browser/cryptoSafetyPrompt.properties
.for j in brand.dtd aboutDialog.dtd aboutTBUpdate.dtd torbutton.dtd onboarding.properties brand.properties torlauncher.properties branding/brand.ftl rulesets.properties settings.properties torConnect.properties onionLocation.properties aboutTor.dtd torbutton.properties browserOnboarding.properties 
	${MKDIR} ${WRKDIR}/.build/dist/bin/chrome/torbutton/locale/${i}/branding
	${CP} ${WRKDIR}/translation-51bc08246d73990d461f747fb3c8cc7b6f66c1f4/${i}/${j} ${WRKDIR}/.build/dist/bin/chrome/torbutton/locale/${i}/${j}
.endfor 
.endfor
post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults ${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/tor-browser.desktop ${STAGEDIR}${PREFIX}/share/applications/tor-browser.desktop
.include <bsd.port.mk>
