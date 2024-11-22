PORTNAME=	tor-browser
DISTVERSION=	14.0.2
CATEGORIES=	www net security wayland
MASTER_SITES=	TOR \
		https://build-sources.tbb.torproject.org/:source1 \
		LOCAL/jsm:source2 \
		https://secure.informaction.com/%SUBDIR%/:source3
MASTER_SITE_SUBDIR=	torbrowser/${DISTVERSION}/:DEFAULT \
			download/releases/:source3
DISTNAME=	src-firefox-tor-browser-128.4.0esr-14.0-1-build3
NOSCRIPT=	noscript-11.5.2.xpi
DISTFILES=	${DISTNAME}.tar.xz \
		manual_215922.zip:source1 \
		fonts-3--4348e1.tar.zst:source2 \
		${NOSCRIPT}:source3

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
		yasm:devel/yasm
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor

USES=		compiler:c++11-lib libtool localbase:ldflags perl5 pkgconfig \
		python:3.8+ shebangfix tar:xz
USE_GECKO=	gecko
USE_GITHUB=	nodefault
TAG_L10N=	878fe6f256d52c7e5b0205b07b061829ccde4f17
GH_TUPLE=	mozilla-l10n:firefox-l10n:${TAG_L10N}:ffl10n
USE_GITLAB=	nodefault
GL_SITE=	https://gitlab.torproject.org/
GL_ACCOUNT=	tpo
GL_PROJECT=	translation:basebrowser translation:torbrowser
TAG_BASE=	5a074e0814015db3c2edbf63ff8e9d1f552900aa
TAG_TOR=	7276d3d2ad0319c3d3762047226da7ee104d1d42
GL_TAGNAME=	${TAG_BASE}:basebrowser ${TAG_TOR}:torbrowser
USE_MOZILLA=	-sqlite

LOCALES=	ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko \
		lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN \
		zh-TW
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_CHROME_MULTILOCALE="${LOCALES}"

MAKE_ENV+=	LOCALES="${LOCALES}"

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
SSP_UNSAFE=		yes

BUNDLE_LIBS=	yes
SUB_FILES=	fonts.conf tor-browser.desktop torrc-defaults

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Tor Browser" \
		MOZ_APP_NAME="tor-browser" \
		MOZ_CHROME_MULTILOCALE="${LOCALES}"

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

.include "${.CURDIR}/../../www/firefox/Makefile.options"

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
MOZILLA_PLIST_DIRS=	bin lib share/applications share/pixmaps \
			share/tor-browser
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif
post-patch:
	@${REINPLACE_CMD} 's|LOCALBASE|${LOCALBASE}|g' \
		"${WRKSRC}/browser/app/profile/000-tor-browser.js"
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp
	${MKDIR} ${WRKSRC}/tmp-manual
	${UNZIP_NATIVE_CMD} -d ${WRKSRC}/tmp-manual ${DISTDIR}/manual_215922.zip
pre-configure:
	@${REINPLACE_CMD} 's|export MOZ_GOOGLE_.*||g' ${WRKSRC}/.mozconfig
	${PYTHON_CMD} ${FILESDIR}/packagemanual.py ${WRKSRC}/tmp-manual/public \
		${WRKSRC}/browser/base/content/manual
post-configure:
	${MKDIR} ${WRKDIR}/.mozbuild/l10n-central
	${CP} -r ${WRKDIR}/firefox-l10n-${TAG_L10N}/* \
		${WRKDIR}/.mozbuild/l10n-central

.for i in ${LOCALES}
	${CP} ${WRKDIR}/translation-${TAG_BASE}/${i}/base-browser.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${CP} ${WRKDIR}/translation-${TAG_BASE}/${i}/newIdentity.properties \
		${WRKDIR}/.mozbuild/l10n-central/${i}/browser/chrome/browser/
	${CP} ${WRKDIR}/translation-${TAG_BASE}/${i}/securityLevel.properties \
		${WRKDIR}/.mozbuild/l10n-central/${i}/browser/chrome/browser/
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/tor-browser.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${MKDIR} ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.for j in aboutTBUpdate.dtd brand.dtd brand.properties onionLocation.properties \
	settings.properties torConnect.properties torbutton.dtd \
	torbutton.properties torlauncher.properties
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/${j} \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.endfor
	${CP} -r ${WRKDIR}/translation-${TAG_TOR}/${i}/branding \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}
.endfor

post-build:
	MOZBUILD_STATE_PATH=${WRKDIR}/.mozbuild AB_CD="multi" MOZ_AUTOMATION="1" \
		PATH="`find ${WRKRDIR}/.mozbuild/srcdirs -name build -type d -print`/bin:${PATH}" \
		${WRKSRC}/mach package-multi-locale --locales ${LOCALES}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults \
		${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/tor-browser.desktop \
		${STAGEDIR}${PREFIX}/share/applications/tor-browser.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tor-browser/fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.conf \
		${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig/fonts.conf
	(cd ${WRKDIR}/fonts && \
		${COPYTREE_SHARE} "*.otf *.ttf" ${STAGEDIR}${PREFIX}/lib/tor-browser/fonts)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions
	${INSTALL_DATA} ${DISTDIR}/${NOSCRIPT} \
		"${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi"

.include <bsd.port.mk>
