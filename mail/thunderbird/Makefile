PORTNAME=	thunderbird
DISTVERSION=	115.14.0
CATEGORIES=	mail news net-im wayland
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source
DISTFILES=	${DISTNAME}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above
WWW=		https://www.mozilla.com/thunderbird/

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.90:security/nss \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=7.3.0:print/harfbuzz \
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
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libbotan-2.so:security/botan2

SSP_UNSAFE=	yes
USE_GECKO=	gecko
# cannot use system icu: calendar is completely broken by
# https://unicode-org.atlassian.net/browse/ICU-22132 (fix not in 74.1)
USE_MOZILLA=	-icu -sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234

USES=		tar:xz

MOZ_OPTIONS=	--enable-application=comm/mail --enable-official-branding
MOZ_OPTIONS+=	--with-system-bz2 --with-system-jsonc --with-system-botan
MOZ_MK_OPTIONS=	MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_EXPORT=		MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1

PORTNAME_ICON=	${MOZILLA}.png
PORTNAME_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}/defaults/pref/${PORTNAME}.js

OPTIONS_DEFAULT=CANBERRA

.include "${.CURDIR}/../../www/firefox/Makefile.options"

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

post-extract:
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON:R}|;s|@MOZILLA@|${MOZILLA}|' \
		<${FILESDIR}/thunderbird.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/comm/mail/app/nsMailApp.cpp

port-pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/defaults

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${LN} -sf ${PORTNAME_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME_ICON}

.include <bsd.port.mk>
