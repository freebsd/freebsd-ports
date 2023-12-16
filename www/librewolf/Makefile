PORTNAME=	librewolf
DISTVERSION=	117.0.1-1
PORTREVISION=	3
CATEGORIES=	www wayland
MASTER_SITES=	https://gitlab.com/api/v4/projects/32320088/packages/generic/librewolf-source/${DISTVERSION:R}-1/
DISTNAME=	${PORTNAME}-${DISTVERSION:R}-1.source.
EXTRACT_SUFX=	tar.gz

PATCH_SITES=	https://gitlab.com/librewolf-community/browser/source/-/raw/5a211f7bad8dcf188a96b408cc143082df8d30a8/
PATCHFILES=	patches/unity_kde/unity-menubar.patch?inline=false:-p1
MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Custom version of Firefox, focused on privacy, security and freedom
WWW=		https://librewolf.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.84:security/nss \
		icu>=71.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=4.4.1:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.37:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.12.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

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
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	MOZ_REQUIRE_SIGNING=""
MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Librewolf" \
		MOZ_APP_NAME="librewolf"

MOZ_OPTIONs=	--enable-application=browser \
		--allow-addon-sideload \
		--disable-crashreporter \
		--disable-debug \
		--disable-default-browser-agent \
		--disable-tests \
		--disable-updater \
		--enable-hardening \
		--enable-optimize \
		--enable-release \
		--enable-rust-simd \
		--with-app-name=librewolf \
		--with-branding=browser/branding/librewolf \
		--with-unsigned-addon-scopes=app,system \
		--with-l10n-base=$PWD/browser/locales/l10n \
		--enable-bootstrap \
		MOZ_CRASHREPORTER=0 \
		MOZ_DATA_REPORTING=0 \
		MOZ_SERVICES_HEALTHREPORT=0

# helpful when testing beta
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}-1

FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
FIREFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp
	@${RM} ${WRKSRC}/mozconfig

post-install:
	${CP} ${FIREFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|Firefox|Librewolf|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|firefox|librewolf|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|Icon=.*|Icon=${FIREFOX_ICON_SRC}|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop

.include <bsd.port.mk>
