PORTNAME=	tor-browser
DISTVERSION=	14.0.1
CATEGORIES=	www net security wayland
MASTER_SITES=	TOR \
		https://build-sources.tbb.torproject.org/:source1 \
		LOCAL/jsm:source2 \
		https://secure.informaction.com/%SUBDIR%/:source3

DISTFILES=	${DISTNAME}.tar.xz \
		manual_215922.zip:source1 \
		fonts-3--4348e1.tar.zst:source2 \
		noscript-11.4.42.xpi:source3
MASTER_SITE_SUBDIR=	torbrowser/${DISTVERSION}/:DEFAULT \
			download/releases/:source3

DISTNAME=	src-firefox-tor-browser-128.4.0esr-14.0-1-build2
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

USE_GITHUB=nodefault
GH_TUPLE=	mozilla-l10n:firefox-l10n:878fe6f256d52c7e5b0205b07b061829ccde4f17:ffl10n
USE_GITLAB=nodefault
GL_SITE=	https://gitlab.torproject.org/
GL_ACCOUNT=	tpo
GL_PROJECT=	translation:basebrowser translation:torbrowser
GL_TAGNAME=	3b1be2065b54939ed019d94174f137847bcf3c66:basebrowser ba63bd165f3fd4bdd472815c9761413d4671cfb7:torbrowser
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor

USES=		compiler:c++11-lib libtool \
		perl5 pkgconfig python shebangfix localbase:ldflags tar:xz python:3
USE_GECKO=	gecko

SSP_UNSAFE=	yes

SUB_FILES=	torrc-defaults tor-browser.desktop fonts.conf
BUNDLE_LIBS=	yes

USE_MOZILLA=	-sqlite
MOZILLA_VER=128.4.0
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_CHROME_MULTILOCALE="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW"

MAKE_ENV+=	 LOCALES="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW"

MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Tor Browser" \
		MOZ_APP_NAME="tor-browser" \
		MOZ_CHROME_MULTILOCALE="ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW"

MOZ_OPTIONS=--with-base-browser-version=14.0.1 \
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

.include	"${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

.if ${ARCH} == amd64
MOZ_OPTIONS+=	--enable-rust-simd
.endif
.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc@${LLVM_VERSION} \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZILLA_PLIST_DIRS=	bin lib share/pixmaps share/applications share/tor-browser
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif
post-patch:
	@${REINPLACE_CMD} 's|LOCALBASE|${LOCALBASE}|g' "${WRKSRC}/browser/app/profile/000-tor-browser.js"
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/browser/app/nsBrowserApp.cpp
	${MKDIR} ${WRKSRC}/tmp-manual
	unzip -d ${WRKSRC}/tmp-manual ${DISTDIR}/manual_215922.zip
pre-configure:
	@${REINPLACE_CMD} 's|export MOZ_GOOGLE_.*||g' ${WRKSRC}/.mozconfig
	${PYTHON_CMD} ${FILESDIR}/packagemanual.py ${WRKSRC}/tmp-manual/public ${WRKSRC}/browser/base/content/manual
post-configure:
	${MKDIR} ${WRKDIR}/.mozbuild/l10n-central
	${CP} -r ${WRKDIR}/firefox-l10n-878fe6f256d52c7e5b0205b07b061829ccde4f17/* ${WRKDIR}/.mozbuild/l10n-central

.for i in ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW
	${CP} ${WRKDIR}/translation-3b1be2065b54939ed019d94174f137847bcf3c66/${i}/base-browser.ftl ${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${CP} ${WRKDIR}/translation-3b1be2065b54939ed019d94174f137847bcf3c66/${i}/newIdentity.properties ${WRKDIR}/.mozbuild/l10n-central/${i}/browser/chrome/browser/
	${CP} ${WRKDIR}/translation-3b1be2065b54939ed019d94174f137847bcf3c66/${i}/securityLevel.properties ${WRKDIR}/.mozbuild/l10n-central/${i}/browser/chrome/browser/
	${CP} ${WRKDIR}/translation-ba63bd165f3fd4bdd472815c9761413d4671cfb7/${i}/tor-browser.ftl ${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${MKDIR} ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.for j in aboutTBUpdate.dtd brand.properties onionLocation.properties torbutton.properties torlauncher.properties brand.dtd settings.properties	torbutton.dtd torConnect.properties
	${CP} ${WRKDIR}/translation-ba63bd165f3fd4bdd472815c9761413d4671cfb7/${i}/${j} ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/

.endfor
	${CP} -r ${WRKDIR}/translation-ba63bd165f3fd4bdd472815c9761413d4671cfb7/${i}/branding ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}
.endfor

post-build:
	MOZBUILD_STATE_PATH=${WRKDIR}/.mozbuild AB_CD="multi" MOZ_AUTOMATION="1" PATH="`find ${WRKRDIR}/.mozbuild/srcdirs -name build -type d -print`/bin:${PATH}" ${WRKSRC}/mach package-multi-locale  --locales ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN zh-TW

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults ${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/tor-browser.desktop ${STAGEDIR}${PREFIX}/share/applications/tor-browser.desktop
	${MKDIR} 		${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig
	${MKDIR} 		${STAGEDIR}${PREFIX}/lib/tor-browser/fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.conf ${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig/fonts.conf
	${CP} ${WRKDIR}/fonts/*.ttf		${STAGEDIR}${PREFIX}/lib/tor-browser/fonts/
	${CP} ${WRKDIR}/fonts/*.otf		${STAGEDIR}${PREFIX}/lib/tor-browser/fonts/
	${CHMOD} 0744 	${STAGEDIR}${PREFIX}/lib/tor-browser/fonts
	${CHMOD} 0744 	${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig/
	${CHMOD} 0644 	${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig/fonts.conf
	${CHMOD} 0644 	${STAGEDIR}${PREFIX}/lib/tor-browser/fonts/*.ttf
	${CHMOD} 0644 	${STAGEDIR}${PREFIX}/lib/tor-browser/fonts/*.otf
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions
	${CP} ${DISTDIR}/noscript-11.4.42.xpi "${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi"

.include <bsd.port.mk>
