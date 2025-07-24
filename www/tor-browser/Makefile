PORTNAME=	tor-browser
DISTVERSION=	14.5.5
CATEGORIES=	www net security wayland
TAG_BASE=	8600afeb12fdae895c37618e1386c1a1ac2f5308
TAG_TOR=	9fe8a13ee4c69f91cd545dc3c575ca8f4851d58e
MASTER_SITES=	TOR \
		LOCAL/vvd \
		https://build-sources.tbb.torproject.org/:source1 \
		LOCAL/vvd:source1 \
		LOCAL/jsm:source2 \
		LOCAL/vvd:source2 \
		https://secure.informaction.com/download/releases/:source3 \
		LOCAL/vvd:source3 \
		https://gitlab.torproject.org/tpo/translation/-/archive/${TAG_BASE}.tar.gz?dummy=/:source4 \
		LOCAL/vvd:source4 \
		https://gitlab.torproject.org/tpo/translation/-/archive/${TAG_TOR}.tar.gz?dummy=/:source5 \
		LOCAL/vvd:source5
MASTER_SITE_SUBDIR=	torbrowser/${DISTVERSION}/:DEFAULT \
			download/releases/:source3
DISTNAME=	src-firefox-tor-browser-128.13.0esr-14.5-1-build2
MANUAL=		manual_215922.zip
NOSCRIPT=	noscript-13.0.8.xpi
DISTFILES=	${DISTNAME}.tar.xz \
		${MANUAL}:source1 \
		fonts-3--4348e1.tar.zst:source2 \
		${NOSCRIPT}:source3 \
		tpo-translation-${TAG_BASE}_GL0.tar.gz:source4 \
		tpo-translation-${TAG_TOR}_GL0.tar.gz:source5

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tor Browser for FreeBSD
WWW=		https://www.torproject.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.101:security/nss \
		icu>=76.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=8.5.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.43:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.14:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor

USES=		compiler:c++11-lib libtool localbase:ldflags perl5 pkgconfig \
		python shebangfix tar:xz
USE_GECKO=	gecko
USE_GITHUB=	nodefault
TAG_L10N=	fcd0300e8478d1ec4d1c097a073ddb8e1e0351e3
GH_TUPLE=	mozilla-l10n:firefox-l10n:${TAG_L10N}:ffl10n
USE_MOZILLA=	-sqlite

LOCALES=	af ar az be bg bs ca cs da de el es-ES et fa fi fr ga-IE gu-IN \
		he hi-IN hr hu hy-AM id is it ja ka km ko lt lv mk mr ms my \
		nb-NO nl nn-NO pa-IN pl pt-BR pt-PT ro ru sk sl sq sr sv-SE ta \
		te th tl tr uk ur vi zh-CN zh-TW

CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	MOZ_CHROME_MULTILOCALE="${LOCALES}"

MAKE_ENV+=	LOCALES="${LOCALES}"

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
SSP_UNSAFE=		yes

BUNDLE_LIBS=	yes
SUB_FILES=	fonts.conf tor-browser.desktop torrc-defaults

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

MOZ_EXPORT=	MOZ_TELEMETRY_REPORTING="" \
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

.if ${ARCH} == i386
BUILD_DEPENDS+=	node${NODEJS_VERSION}>=24:www/node${NODEJS_VERSION}
USES+=		nodejs:24,build,env
.  if ${MACHINE_CPU:Msse2}
# is not enabled on i386 by default
# Fix for error: always_inline function '_mm_setzero_si64' requires target feature 'sse2'
CFLAGS_i386+=	-msse2
.  endif
.endif

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
	${UNZIP_NATIVE_CMD} -d ${WRKSRC}/tmp-manual ${DISTDIR}/${MANUAL}

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
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/tor-browser.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${MKDIR} ${WRKDIR}/.mozbuild/l10n-central/${i}/browser/branding/tb-release \
		 ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/brand.properties \
	      ${WRKDIR}/translation-${TAG_TOR}/${i}/branding/brand.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/browser/branding/tb-release
. for j in onionLocation.properties settings.properties torConnect.properties \
	torlauncher.properties
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/${j} \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
. endfor
	${CP} -r ${WRKDIR}/translation-${TAG_TOR}/${i}/branding \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.endfor

post-build:
	MOZBUILD_STATE_PATH=${WRKDIR}/.mozbuild AB_CD="multi" MOZ_AUTOMATION="1" \
		PATH="`find ${WRKRDIR}/.mozbuild/srcdirs -name build -type d -print`/bin:${PATH}" \
		${WRKSRC}/mach package-multi-locale --locales ${LOCALES}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
		 ${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig \
		 ${STAGEDIR}${PREFIX}/lib/tor-browser/fonts \
		 ${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults \
		${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/tor-browser.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/fonts.conf \
		${STAGEDIR}${PREFIX}/lib/tor-browser/fontconfig/fonts.conf
	(cd ${WRKDIR}/fonts && \
		${COPYTREE_SHARE} "*.otf *.ttf" ${STAGEDIR}${PREFIX}/lib/tor-browser/fonts)
	${INSTALL_DATA} ${DISTDIR}/${NOSCRIPT} \
		"${STAGEDIR}${PREFIX}/lib/tor-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi"

.include <bsd.port.mk>
