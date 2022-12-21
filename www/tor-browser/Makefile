PORTNAME=	tor-browser
DISTVERSION=	12.0-2
CATEGORIES=	www net security
MASTER_SITES=	https://dist.torproject.org/torbrowser/12.0/
DISTNAME=	src-firefox-tor-browser-102.5.0esr-${DISTVERSION}-build1

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tor Browser for FreeBSD
WWW=		https://www.torproject.org/

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.79.1:security/nss \
		icu>=71.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=4.1.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.37:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.11.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip
LIB_DEPENDS=	libgconf-2.so:devel/gconf2 \
		libgtk-x11-2.0.so:x11-toolkits/gtk20 \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpulse.so:audio/pulseaudio \
		libXt.so:x11-toolkits/libXt \
		libIDL-2.so:devel/libIDL \
		libnspr4.so:devel/nspr
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor

USES=		compiler:c++11-lib libtool \
		perl5 pkgconfig python:3.4+ shebangfix localbase:ldflags tar:xz
USE_GECKO=	gecko

SSP_UNSAFE=	yes

SUB_FILES=	torrc-defaults tor-browser.desktop
BUNDLE_LIBS=	yes

USE_MOZILLA=	-sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_BRANDING_DIRECTORY="browser/branding/official"

MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Tor Browser" \
		MOZ_APP_NAME="tor-browser"

MOZ_OPTIONS=	--with-tor-browser-version=12.0-2 \
	--enable-official-branding \
	--enable-optimize \
	--enable-rust-simd \
	--enable-bundled-fonts \
	--disable-tests \
	--disable-debug \
	--disable-crashreporter \
	--disable-webrtc \
	--disable-parental-controls \
	--enable-proxy-bypass-protection \
	--disable-system-policies \
	--disable-backgroundtasks \
	--enable-base-browser \
	--enable-verify-mar \
	--with-distribution-id=org.torproject

WRKSRC=		${WRKDIR}/firefox-tor-browser-102.5.0esr-12.0-2-build1

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--disable-webrtc --without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/clang/${LLVM_VERSION}/lib/wasi/libclang_rt.builtins-wasm32.a:devel/wasi-compiler-rt${LLVM_DEFAULT}
MOZILLA_PLIST_DIRS=	bin lib share/pixmaps share/applications share/tor-browser
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif
post-patch:
	@${REINPLACE_CMD} 's|LOCALBASE|${LOCALBASE}|g' "${WRKSRC}/browser/app/profile/000-tor-browser.js"
pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)
	@${REINPLACE_CMD} 's|export MOZ_GOOGLE_.*||g' ${WRKSRC}/.mozconfig
	@${REINPLACE_CMD} 's|ac_add_options --enable-update-channel=release||g' ${WRKSRC}/.mozconfig
post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults ${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/tor-browser.desktop ${STAGEDIR}${PREFIX}/share/applications/tor-browser.desktop
.include <bsd.port.mk>
