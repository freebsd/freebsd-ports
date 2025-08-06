PORTNAME=	firefox
DISTVERSION=	141.0.3
PORTEPOCH=	2
CATEGORIES=	www wayland
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}${DISTVERSIONSUFFIX}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}${DISTVERSIONSUFFIX}-candidates/build1/source
DISTFILES=	${DISTNAME}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla
WWW=		https://www.mozilla.com/firefox

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
CONFLICTS_INSTALL=	firefox-esr
USE_MOZILLA=	-sqlite
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"

USES=		tar:xz
# helpful when testing beta
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--enable-application=browser \
		--enable-official-branding \
		--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot

.include "${.CURDIR}/../../www/firefox/Makefile.options"

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON:R}|;s|@MOZILLA@|${MOZILLA}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
