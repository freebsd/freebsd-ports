# $FreeBSD$

PORTNAME=	cinelerra-gg
DISTVERSION=	5.1-20180714
DISTVERSIONSUFFIX=	-${REV:C/(.......).*/\1/}
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	https://git.cinelerra-cv.org/gitweb?p=goodguy/cinelerra.git;a=snapshot;h=${REV};sf=tgz;dummy=/ # tarballs are @ https://cinelerra-cv.org/five/pkgs/src/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Professional video editing and compositing environment

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${BUILD_WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not designed for other architectures

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		yasm:devel/yasm \
		${LOCALBASE}/include/libdv/dv.h:multimedia/libdv \
		${LOCALBASE}/include/mjpegtools/yuv4mpeg.h:multimedia/mjpegtools
LIB_DEPENDS=	libFLAC.so:audio/flac \
		libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libIex.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libogg.so:audio/libogg \
		libopenjp2.so:graphics/openjpeg \
		libopus.so:audio/opus \
		libpng.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libtheoraenc.so:multimedia/libtheora \
		libtiff.so:graphics/tiff \
		libuuid.so:misc/e2fsprogs-libuuid \
		libvorbis.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp \
		libx264.so:multimedia/libx264 \
		libx265.so:multimedia/x265
RUN_DEPENDS=	bash:shells/bash

EXTRA_PATCHES=	${BUILD_WRKSRC}/blds/bsd.patch:-p1

REV=		502b6f3b6fd04f6b01c6d70dcb81aa304dd0db1c # git revision

USES=		autoreconf gettext-runtime gettext-tools gmake iconv:wchar_t \
		jpeg localbase makeinfo python:2.7,build shebangfix xorg
SHEBANG_GLOB=	*.sh *.bld
GNU_CONFIGURE=	yes
USE_XORG=	x11 xau xdmcp xext xfixes xft xinerama xv

MAKE_ENV=	C_INCLUDE_PATH=${LOCALBASE}/include CPLUS_INCLUDE_PATH=${LOCALBASE}/include LIBRARY_PATH=${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-static-build --disable-lame --disable-twolame \
		--with-oss --without-alsa \
		--without-firewire --without-dv --without-dvb \
		--without-video4linux2 --without-xxf86vm --without-ladspa-build \
		--without-libzmpeg --without-commercial --without-thirdparty
CFLAGS+=	-DFFMPEG3
BINARY_ALIAS=	make=gmake

WRKSRC=			${WRKDIR}/cinelerra-${REV:C/(.......).*/\1/}
AUTORECONF_WRKSRC=	${BUILD_WRKSRC}
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
BUILD_WRKSRC=		${WRKSRC}/cinelerra-${DISTVERSION:C/-.*//}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

DATADIR=		${PREFIX}/share/cin

OPTIONS_DEFINE=		LV2 OPENGL
OPTIONS_DEFAULT=	LV2 OPENGL
OPTIONS_SUB=		yes

LV2_DESC=		Use LV2 plugins
LV2_CONFIGURE_WITH=	lv2
LV2_USES=		gnome pkgconfig
LV2_USE=		GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
LV2_CFLAGS=		-I${LOCALBASE}/include/lilv-0 -I${LOCALBASE}/include/suil-0
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libserd-0.so:devel/serd \
			libsord-0.so:devel/sord \
			libsratom-0.so:audio/sratom \
			libsuil-0.so:audio/suil

OPENGL_CONFIGURE_WITH=	gl
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu

post-patch:
	# the patch recommended by the upstream
	@cd ${CONFIGURE_WRKSRC}/ffmpeg && \
		for f in `grep -lr libfdk_ .`; do ${REINPLACE_CMD} -e 's/libfdk_//' -i '' $$f; done;
	# correct the bash interpreter path
	@cd ${CONFIGURE_WRKSRC}/cinelerra && ${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		../configure.ac bdcreate.C dvdcreate.C shbtnprefs.C

do-configure: # configure needs bash
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
