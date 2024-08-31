PORTNAME=	makemkv
DISTVERSION=	1.17.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.makemkv.com/download/:makemkv \
		http://www.makemkv.com/download/old/:makemkv \
		SF/opencore-amr/fdk-aac/:fdkaac \
		https://ffmpeg.org/releases/:ffmpeg
DISTFILES=	${DISTFL_MAKEMKV:S/$/:makemkv/} \
		${DISTFL_FFMPEG:S/$/:ffmpeg/}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Video converter reading from DVD and Bluray
WWW=		https://www.makemkv.com

LICENSE=		MAKEMKV LGPL21+ ${PORT_OPTIONS:MFDK_AAC}
LICENSE_COMB=		multi
LICENSE_NAME_MAKEMKV=	The MakeMKV EULA
LICENSE_NAME_FDK_AAC=	The FDK AAC License
LICENSE_FILE_MAKEMKV=	${WRKSRC_bin}/src/eula_en_linux.txt
LICENSE_FILE_FDK_AAC=	${WRKSRC_fdkaac}/NOTICE
LICENSE_PERMS_MAKEMKV=	dist-mirror pkg-mirror auto-accept \
			# eplicit permission granted by copyright owner to \
			# distribute a patched makemkvcon binary.
LICENSE_PERMS_FDK_AAC=	auto-accept
LICENSE_DISTFILES_FDK_AAC=	${DISTFL_FDKAAC}
LICENSE_DISTFILES_LGPL21+ =	${DISTFL_FFMPEG}
LICENSE_DISTFILES_MAKEMKV=	${DISTFL_MAKEMKV}

ONLY_FOR_ARCHS=	aarch64 amd64 i386
USES=		gmake linux pkgconfig
USE_CSTD=	c11
USE_CXXSTD=	c++11
USE_LINUX=	base expat \
		devtools:build expat-devel:build openssl-devel:build \
		zlib-devel:build
BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		${BUILD_DEPENDS_${FFMPEG_ARCH}}
BUILD_DEPENDS_x86=	nasm:devel/nasm

WRKSRC=		${WRKDIR}/makemkv-oss-${DISTVERSION}
WRKSRC_bin=	${WRKDIR}/makemkv-bin-${DISTVERSION}
WRKSRC_fdkaac=	${WRKDIR}/fdk-aac-${FDKAACVERSION}
WRKSRC_ffmpeg=	${WRKDIR}/ffmpeg-${FFMPEGVERSION}

CONFLICTS_BUILD=	v4l_compat

SUB_FILES=	update-makemkv-drives
SUB_LIST=	LINUXBASE=${LINUXBASE}
PLIST_SUB=	LINUXBASE=${LINUXBASE}

FDKAACVERSION=	2.0.3
FFMPEGVERSION=	6.1.2

DISTFL_MAKEMKV=	makemkv-oss-${DISTVERSION}.tar.gz \
		makemkv-bin-${DISTVERSION}.tar.gz
DISTFL_FDKAAC=	fdk-aac-${FDKAACVERSION}.tar.gz
DISTFL_FFMPEG=	ffmpeg-${FFMPEGVERSION}.tar.xz

OPTIONS_DEFINE=		EXAMPLES FDK_AAC
OPTIONS_DEFAULT=	EXAMPLES
FDK_AAC_DESC=		Support AAC via statically linked fdk-aac
FDK_AAC_DISTFILES=	${DISTFL_FDKAAC:S/$/:fdkaac/}
TARGET_ORDER_OVERRIDE=	290:pre-configure-FDK_AAC-on

CC=		${LINUXBASE}/bin/gcc
CXX=		${LINUXBASE}/bin/g++
CPPFLAGS+=	-D_linux_ -DFORCE_OPENSSL_NO_EC
PATCHELF_CMD?=	${LOCALBASE}/bin/patchelf
LINUXSYSROOT=	${WRKDIR}/gnuroot
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-gui --libdir=${PREFIX}/lib/makemkv
CONFIGURE_ENV=	PKG_CONFIG_PATH=${LINUXSYSROOT}/lib/pkgconfig
MAKE_ARGS=	CFLAGS="${CXXFLAGS} ${CPPFLAGS} -std=c11"

FFMPEG_ARCH=		${ARCH:Maarch64:S/^$/x86/}
FFMPEG_CONFIGURE_ARGS=	--prefix=${LINUXSYSROOT} --pkg-config=pkg-config \
			--disable-shared --enable-static --enable-pic \
			--target-os=linux --cc=${CC} \
			${"${PORT_OPTIONS:MFDK_AAC}":?--enable-libfdk-aac:}
FFMPEG_CONFIGURE_ENV=	${CONFIGURE_ENV} CFLAGS="${CPPFLAGS} ${CFLAGS}"
FFMPEG_MAKE_ARGS=	V=1 ARCH=${FFMPEG_ARCH}
FFMPEG_INSTALL_TARGET=	${ALL_TARGET} ${INSTALL_TARGET}

post-patch:
		@${REINPLACE_CMD} -e 's:INSTALL) -D:INSTALL):' \
			${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e 's:/bin/bash:/bin/sh:' \
			-e 's:x86_64:amd64:' \
			-e 's:i686:i386:' \
			-e 's:-t \([^ ]*\) \([^ ]*\):\2 \1:' \
			-e 's:ARCH=:BINARCH=:' \
			-e 's:bin/$$(ARCH:bin/$$(BINARCH:' \
			${WRKSRC_bin}/Makefile

pre-configure-FDK_AAC-on:
		cd ${WRKSRC_fdkaac}; \
		${CONFIGURE_ENV} CXX=${CXX} \
		./configure --prefix=${LINUXSYSROOT} --disable-silent-rules \
			--disable-shared --enable-static --with-pic; \
		${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${INSTALL_TARGET}

pre-configure:
		cd ${WRKSRC_ffmpeg}; \
		${FFMPEG_CONFIGURE_ENV} ./configure ${FFMPEG_CONFIGURE_ARGS}; \
		${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} \
			${FFMPEG_MAKE_ARGS} ${FFMPEG_INSTALL_TARGET}

pre-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/makemkv

post-install:
		${INSTALL_MAN} ${FILESDIR}/makemkvcon.1 \
			${STAGEDIR}${PREFIX}/share/man/man1
		cd ${WRKSRC_bin}; \
		${MKDIR} tmp; \
		${ECHO_CMD} accepted > tmp/eula_accepted; \
		${MAKE_CMD} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} install
		${PATCHELF_CMD} --set-rpath ${PREFIX}/lib/makemkv \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		${REINPLACE_CMD} -e 's:/sys/bus/scsi:/etc/makemkv/:' \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		${BRANDELF} -t Linux ${STAGEDIR}${PREFIX}/bin/makemkvcon
		${INSTALL_SCRIPT} ${WRKDIR}/update-makemkv-drives \
			${STAGEDIR}${PREFIX}/sbin

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${FILESDIR}/update-makemkv-key.sh \
			${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
