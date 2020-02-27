# $FreeBSD$

PORTNAME=	cliqz
DISTVERSION=	1.33.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/:amazon \
		http://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/${CLIQZ_LAST_BUILD_ID}/:cliqz
DISTFILES=	adult-domains.bin:amazon \
		cliqz@cliqz.com.xpi:cliqz \
		dat@cliqz.com.xpi:cliqz \
		gdprtool@cliqz.com.xpi:cliqz \
		https-everywhere@cliqz.com.xpi:cliqz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Secure browser (Mozilla based) with built-in quick search

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	ca_root_nss>=0:security/ca_root_nss
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libnspr4.so:devel/nspr \
		libnssutil3.so:security/nss \
		libplc4.so:devel/nspr \
		libplds4.so:devel/nspr

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${RUST_DEFAULT}>=1.39:lang/${RUST_DEFAULT} \
		autoconf-2.13:devel/autoconf213 \
		bash:shells/bash \
		graphite2>=1.3.13:graphics/graphite2 \
		harfbuzz>=2.6.1:print/harfbuzz \
		icu>=64.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		libvorbis>=1.3.6,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		${LOCALBASE}/bin/python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//g} \
		llvm${LLVM_DEFAULT}>=0:devel/llvm${LLVM_DEFAULT} \
		nasm:devel/nasm \
		node:www/node \
		nspr>=4.24:devel/nspr \
		nss>=3.49.2:security/nss \
		png>=1.6.35:graphics/png \
		rust-cbindgen>=0.12.0:devel/rust-cbindgen \
		sqlite3>=3.30.1:databases/sqlite3 \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm \
		zip:archivers/zip

USES=		compiler:c++17-lang desktop-file-utils gmake gnome pkgconfig \
		python:2.7,build shebangfix tar:xz xorg

USE_GNOME=	cairo gconf2 gdkpixbuf2 gtk20 gtk30

USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xrender xt

USE_GITHUB=	yes
GH_ACCOUNT=	cliqz-oss
GH_PROJECT=	browser-f

USE_LDCONFIG=	yes

bash_OLD_CMD=	"/bin/bash"
bash_CMD=	${LOCALBASE}/bin/bash
SHEBANG_FILES=	magic_build_and_package.sh

CLIQZ_CHANNEL=		release
# If the DISTVERSION is updated, make sure to update the last build id from
# fetch -qo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20200219152122
CLIQZ_ICON=		${PORTNAME}.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/${PORTNAME}/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID} \
		CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL} \
		LLVM_CONFIG=llvm-config${LLVM_DEFAULT} \
		LLVM_OBJDUMP=${LOCALBASE}/llvm${LLVM_DEFAULT}/bin/llvm-objdump \
		PYTHON3="${LOCALBASE}/bin/python${PYTHON3_DEFAULT}" \
		RUSTFLAGS=${RUSTFLAGS} \
		MOZBUILD_STATE_PATH=${WRKDIR}

# Configure args passed into mach build system
MOZ_CONFIGURE_ARGS+=	"--disable-crashreporter" \
			"--disable-debug" \
			"--disable-debug-symbols" \
			"--disable-tests" \
			"--disable-updater" \
			"--libclang-path=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib" \
			"--with-system-graphite2" \
			"--with-system-harfbuzz"

.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

# Adjust -C target-cpu if -march/-mcpu is set by bsd.cpu.mk
.if ${ARCH} == amd64 || ${ARCH} == i386
RUSTFLAGS+=	${CFLAGS:M-march=*:S/-march=/-C target-cpu=/}
.else
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/}
.endif

.if ${ARCH:Maarch64} || ${MACHINE_CPU:Msse2}
MOZ_CONFIGURE_ARGS+=	"--enable-rust-simd"
.else
MOZ_CONFIGURE_ARGS+=	"--disable-rust-simd"
.endif

# Require newer Clang than what's in base system unless user opted out
.if ${CC} == cc && ${CXX} == c++ && exists(/usr/lib/libc++.so)
CPP=		${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CC=		${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CXX=		${LOCALBASE}/bin/clang++${LLVM_DEFAULT}
# XXX avoid warnings
USES:=		${USES:Ncompiler\:*}
.endif

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/adult-domains.bin ${WRKSRC}
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cliqz@cliqz.com.xpi \
		${DISTDIR}/${DIST_SUBDIR}/https-everywhere@cliqz.com.xpi \
		${DISTDIR}/${DIST_SUBDIR}/gdprtool@cliqz.com.xpi \
		${WRKSRC}/obj/dist/bin/browser/features

post-patch:
	@${CP} ${MOZ_DESKTOP} ${CLIQZ_DESKTOP}
	@${REINPLACE_CMD} -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/${PORTNAME}/g' \
		-e '/Icon=${PORTNAME}/ s/${PORTNAME}/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		${CLIQZ_DESKTOP}
.for MOZ_CONFIGURE_ARG in ${MOZ_CONFIGURE_ARGS}
	@${ECHO_CMD} "ac_add_options" ${MOZ_CONFIGURE_ARG} >> \
		${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig;
.endfor
# This prevents linker exhausting memory in i386 builds
.if ${ARCH} == "i386"
	@${ECHO_CMD} 'export LDFLAGS="-Wl,--no-keep-memory -Wl,--as-needed"' >> \
		${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig
.endif
# Disable vendor checksums like lang/rust
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${WRKSRC}/mozilla-release/third_party/rust/*/.cargo-checksum.json

pre-configure-script:
	# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/obj/dist/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	# Check if the wayland lib was generated, this happens if
	# x11-toolkits/gtk30 has WAYLAND option enabled.
	@if [ -f ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libmozwayland.so ]; then \
		${REINPLACE_CMD} -e 's|%%WAYLAND%%||' ${TMPPLIST}; \
	else \
		${REINPLACE_CMD} -e 's|%%WAYLAND%%|@comment |' ${TMPPLIST}; \
	fi
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	@${CP} ${CLIQZ_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include <bsd.port.post.mk>
