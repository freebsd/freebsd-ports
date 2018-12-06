# $FreeBSD$

PORTNAME=	cliqz
DISTVERSION=	1.23.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/:amazon \
		http://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/${CLIQZ_LAST_BUILD_ID}/:cliqz
DISTFILES=	adult-domains.bin:amazon \
		cliqz@cliqz.com.xpi:cliqz \
		https-everywhere@cliqz.com.xpi:cliqz \
		gdprtool@cliqz.com.xpi:cliqz
EXTRACT_ONLY=	${DISTNAME}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Secure browser (Mozilla based) with built-in quick search

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	ca_root_nss>=0:security/ca_root_nss
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnspr4.so:devel/nspr \
		libplc4.so:devel/nspr \
		libplds4.so:devel/nspr \
		libnssutil3.so:security/nss

BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213 \
		bash:shells/bash \
		graphite2>=1.3.12:graphics/graphite2 \
		harfbuzz>=1.8.8:print/harfbuzz \
		icu>=59.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		libvorbis>=1.3.6,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt \
		llvm${LLVM_DEFAULT}>=0:devel/llvm${LLVM_DEFAULT} \
		node:www/node \
		nspr>=4.19:devel/nspr \
		nss>=3.39:security/nss \
		png>=1.6.34:graphics/png \
		${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		rust>=1.28:lang/rust \
		rust-cbindgen>=0.6.2:devel/rust-cbindgen \
		sqlite3>=3.24.0:databases/sqlite3 \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm \
		zip:archivers/zip

USES=		tar:xz gmake pkgconfig gnome python desktop-file-utils \
		compiler:c11

USE_GNOME=	gconf2 gtk20 gtk30 cairo gdkpixbuf2

USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xrender \
		xcb xt

USE_GITHUB=	yes
GH_ACCOUNT=	cliqz-oss
GH_PROJECT=	browser-f

USE_LDCONFIG=	yes

CLIQZ_CHANNEL=		release
# If the DISTVERSION is updated, make sure to update the last build id from
# fetch -qo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20181116003917
CLIQZ_ICON=		${PORTNAME}.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/${PORTNAME}/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

MAKE_ENV+=	LLVM_CONFIG=llvm-config${LLVM_DEFAULT}
MAKE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/adult-domains.bin ${WRKSRC}
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cliqz@cliqz.com.xpi \
		${DISTDIR}/${DIST_SUBDIR}/https-everywhere@cliqz.com.xpi \
		${DISTDIR}/${DIST_SUBDIR}/gdprtool@cliqz.com.xpi \
		${WRKSRC}/obj/dist/bin/browser/features

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${MOZ_DESKTOP} ${CLIQZ_DESKTOP}
	@${REINPLACE_CMD} -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/${PORTNAME}/g' \
		-e '/Icon=${PORTNAME}/ s/${PORTNAME}/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		${CLIQZ_DESKTOP}
.if ${ARCH} == "i386"
	# This prevents linker exhausting memory in i386 builds
	@${ECHO_CMD} 'export LDFLAGS="-Wl,--no-keep-memory -Wl,--as-needed"' >> \
		${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig
.endif

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/obj/dist/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}

post-install:
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	@${CP} ${CLIQZ_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include <bsd.port.post.mk>
