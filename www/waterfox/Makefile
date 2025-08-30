PORTNAME=	waterfox
DISTVERSION=	6.6.2
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Distilled fork of Firefox
WWW=		https://www.waterfox.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.112:security/nss \
		icu>=76.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=10.1.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.45:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.15.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc@${LLVM_VERSION} \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}

USE_GECKO=	gecko
USE_GITHUB=	yes
GH_ACCOUNT=	BrowserWorks
GH_TUPLE=	BrowserWorks:l10n:394dfec:l10n/waterfox/browser/locales
USE_MOZILLA=	-sqlite
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	MOZ_REQUIRE_SIGNING=""

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png

MOZILLA_CAP=	${MOZILLA:C/^(.).*/\1/:tu}${MOZILLA:C/^.//}

MOZ_EXPORT=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="${MOZILLA_CAP}" \
		MOZ_APP_NAME="${MOZILLA}"

MOZ_OPTIONS=	--enable-application=browser \
		--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot \
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

.include "${.CURDIR}/../../www/firefox/Makefile.options"

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ${MACHINE_CPU:Msse2}
# is not enabled on i386 by default
# Fix for error: always_inline function '_mm_setzero_si64' requires target feature 'sse2'
CFLAGS_i386+=	-msse2
.endif

.if ${ARCH} == amd64
MOZ_OPTIONS+=	--enable-rust-simd
.endif

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON:R}|;s|@MOZILLA@|${MOZILLA}|' \
		<${FILESDIR}/waterfox.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
