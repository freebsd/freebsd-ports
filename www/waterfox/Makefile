PORTNAME=	waterfox
DISTVERSIONPREFIX=	G
DISTVERSION=	6.0.18
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Distilled fork of Firefox
WWW=		https://www.waterfox.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.95:security/nss \
		icu>=74.2:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=8.3.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.39:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.13.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

USE_GITHUB=	yes
GH_ACCOUNT=	BrowserWorks
GH_PROJECT=	Waterfox

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

.if ${ARCH} != powerpc64
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
.endif

USE_GECKO=	gecko
USE_MOZILLA=	-sqlite

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
MOZILLA_CAP=	${MOZILLA:C/^(.).*/\1/:tu}${MOZILLA:C/^.//}
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_REQUIRE_SIGNING=""
MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="${MOZILLA_CAP}" \
		MOZ_APP_NAME="${MOZILLA}"

MOZ_OPTIONS+=	--enable-application=browser \
		--allow-addon-sideload \
		--disable-crashreporter \
		--disable-debug \
		--disable-default-browser-agent \
		--disable-tests \
		--disable-updater \
		--enable-hardening \
		--enable-optimize \
		--enable-release \
		--with-app-name=${MOZILLA} \
		--with-unsigned-addon-scopes=app,system \
		--enable-bootstrap \
		MOZ_CRASHREPORTER=0 \
		MOZ_DATA_REPORTING=0

BINARY_ALIAS+=	python3=${PYTHON_CMD}

USE_GECKO=	gecko

WATERFOX_ICON=		${MOZILLA}.png
WATERFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
WATERFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop

.if ${ARCH} == amd64
MOZ_OPTIONS+=	--enable-rust-simd
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-DHWY_COMPILE_ONLY_SCALAR
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e 's/firefox/${MOZILLA}/' \
		-e 's/Firefox/${MOZILLA_CAP}/' \
		-e '/^Icon/s/=.*/=${WATERFOX_ICON:R}/' \
		${WATERFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

post-install:
	${INSTALL_DATA} ${WATERFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${WATERFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${WATERFOX_ICON}

.include <bsd.port.mk>
