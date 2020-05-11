# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	makemkv
PORTVERSION=	1.15.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.makemkv.com/download/:makemkv \
		http://www.makemkv.com/download/old/:makemkv \
		KERNEL_ORG/linux/kernel/v2.6:linux \
		GNU/binutils:binutils \
		GNU/glibc:glibc \
		GNU/gmp:gmp \
		GNU/mpfr:mpfr \
		GNU/mpc:mpc \
		GCC/releases/gcc-${GCCVERSION}:gcc \
		SF/opencore-amr/fdk-aac/:fdkaac \
		https://ffmpeg.org/releases/:ffmpeg \
		https://www.openssl.org/source/old/${OPENSSLVERSION}/:openssl
DISTFILES=	makemkv-oss-${PORTVERSION}.tar.gz:makemkv \
		makemkv-bin-${PORTVERSION}.tar.gz:makemkv \
		linux-${LINUXVERSION}.tar.xz:linux \
		binutils-${BINUTILSVERSION}.tar.bz2:binutils \
		glibc-${GLIBCVERSION}.tar.xz:glibc \
		gmp-${GMPVERSION}.tar.xz:gmp \
		mpfr-${MPFRVERSION}.tar.xz:mpfr \
		mpc-${MPCVERSION}.tar.gz:mpc \
		gcc-${GCCVERSION}.tar.gz:gcc \
		fdk-aac-${FDKAACVERSION}.tar.gz:fdkaac \
		ffmpeg-${FFMPEGVERSION}.tar.bz2:ffmpeg \
		openssl-${OPENSSLFULLVER}.tar.gz:openssl
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	felix@palmen-it.de
COMMENT=	Video converter reading from DVD and Bluray

LICENSE=	MAKEMKV FDK GPLv2 GPLv3 LGPL21+ LGPL3 OpenSSL
LICENSE_COMB=	multi
LICENSE_NAME_MAKEMKV=	The MakeMKV EULA
LICENSE_NAME_FDK=	The FDK AAC License
LICENSE_FILE_MAKEMKV=	${WRKDIR}/makemkv-bin-${PORTVERSION}/src/eula_en_linux.txt
LICENSE_FILE_FDK=	${WRKDIR}/fdk-aac-${FDKAACVERSION}/NOTICE
LICENSE_PERMS_MAKEMKV=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept
LICENSE_PERMS_FDK=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept
LICENSE_DISTFILES_FDK=	fdk-aac-${FDKAACVERSION}.tar.gz
LICENSE_DISTFILES_GPLv2=	binutils-${BINUTILSVERSION}.tar.bz2 \
				glibc-${GLIBCVERSION}.tar.xz \
				linux-${LINUXVERSION}.tar.xz \
				gcc-${GCCVERSION}.tar.gz
LICENSE_DISTFILES_LGPL21+ =	ffmpeg-${FFMPEGVERSION}.tar.bz2
LICENSE_DISTFILES_GPLv3=	gmp-${GMPVERSION}.tar.xz \
				mpfr-${MPFRVERSION}.tar.xz
LICENSE_DISTFILES_LGPL3=	mpc-${MPCVERSION}.tar.gz
LICENSE_DISTFILES_OpenSSL=	openssl-${OPENSSLFULLVER}.tar.gz
LICENSE_DISTFILES_MAKEMKV=	makemkv-bin-${PORTVERSION}.tar.gz \
				makemkv-oss-${PORTVERSION}.tar.gz

ONLY_FOR_ARCHS=	amd64 i386
USES=	gmake linux pkgconfig perl5
USE_LINUX=	base expat expat:build openssl openssl:build
USE_PERL5=	build
USE_GCC=	yes
USE_LDCONFIG=	yes
BUILD_DEPENDS=	nasm>0:devel/nasm \
		${LOCALBASE}/include/expat.h:textproc/expat2 \
		patchelf>0:sysutils/patchelf \
		gawk>0:lang/gawk \
		gsed>0:textproc/gsed

NO_CDROM=	Do not sell
RESTRICTED_FILES=	makemkv-bin-${PORTVERSION}.tar.gz
LEGAL_TEXT=	${NO_CDROM}. Do not redistribute modified binaries, but\
		explicit permission to distribute a patched makemkvcon given\
		by copyright owner

WRKSRC=		${WRKDIR}/makemkv-oss-${PORTVERSION}

SUB_FILES=	update-makemkv-drives
SUB_LIST=	LINUXBASE=${LINUXBASE}
PLIST_SUB=	LINUXBASE=${LINUXBASE}

LINUXVERSION=	2.6.32.27
BINUTILSVERSION=	2.27
GLIBCVERSION=	2.17
GMPVERSION=	5.1.3
MPFRVERSION=	3.1.2
MPCVERSION=	1.0.3
GCCVERSION=	5.5.0
FDKAACVERSION=	2.0.1
FFMPEGVERSION=	4.2.2
OPENSSLVERSION=	1.0.2
OPENSSLPATCHLEVEL=	k
OPENSSLFULLVER=	${OPENSSLVERSION}${OPENSSLPATCHLEVEL}

LINUXARCH=	${ARCH:S/amd64/x86_64/}
LINUXTRIPLET=	${LINUXARCH}-unknown-linux-gnu
LINUX32CPUTYPE=	${${OSVERSION} >= 1300000:?i686:i486}
LINUXTRIPLET=	${LINUXARCH:S/i386/${LINUX32CPUTYPE}/}-unknown-linux-gnu
LINUXLIBDIR=	${LINUXBASE}/${"${LINUXARCH:Mx86_64}" != "":?lib64:lib}
GNUCROSSDIR=	${WRKDIR}/gnuroot/${LINUXTRIPLET}
GNUCROSSLIBDIR=	${GNUCROSSDIR}/${"${LINUXARCH:Mx86_64}" != "":?lib64:lib}
OPENSSLTARGET=	${"${LINUXARCH:Mx86_64}" != "":?linux-x86_64:linux-elf}

PATCHELF_CMD?=	${LOCALBASE}/bin/patchelf

CFLAGS+=	-DFORCE_OPENSSL_NO_EC -I${WRKDIR}/gnuroot/include \
		-I${WRKDIR}/openssl-${OPENSSLFULLVER}/include
SSP_CFLAGS=
LDFLAGS+=	-L${WRKDIR}/gnuroot/lib -Wl,-rpath-link=${WRKDIR}/gnuroot/lib
HAS_CONFIGURE=	yes
MAKE_ENV=	PATH=${WRKDIR}/gnuroot/bin:${PATH}
STRIP_CMD=	${WRKDIR}/gnuroot/bin/${LINUXTRIPLET}-strip

post-extract:
		@${MV} -f ${WRKDIR}/gmp-${GMPVERSION} \
			${WRKDIR}/gcc-${GCCVERSION}/gmp
		@${MV} -f ${WRKDIR}/mpfr-${MPFRVERSION} \
			${WRKDIR}/gcc-${GCCVERSION}/mpfr
		@${MV} -f ${WRKDIR}/mpc-${MPCVERSION} \
			${WRKDIR}/gcc-${GCCVERSION}/mpc
		@${MKDIR} ${WRKDIR}/gnuroot/lib
		@cd ${WRKDIR}/gnuroot/lib; \
			${LN} -s ${LINUXLIBDIR}/libz.so.1; \
			${LN} -s libz.so.1 libz.so; \
			${LN} -s ${LINUXLIBDIR}/libcrypto.so.10; \
			${LN} -s libcrypto.so.10 libcrypto.so; \
			${LN} -s ${LINUXLIBDIR}/libexpat.so.1; \
			${LN} -s libexpat.so.1 libexpat.so
		@${MKDIR} ${WRKDIR}/gnuroot/include
		@cd ${WRKDIR}/gnuroot/include; \
			${LN} -s /usr/include/zlib.h; \
			${LN} -s /usr/include/zconf.h; \
			${LN} -s ${LOCALBASE}/include/expat.h; \
			${LN} -s ${LOCALBASE}/include/expat_config.h; \
			${LN} -s ${LOCALBASE}/include/expat_external.h
		@${MKDIR} ${WRKDIR}/binutils-build
		@${MKDIR} ${WRKDIR}/gcc-build
		@${MKDIR} ${WRKDIR}/glibc-build

post-patch:
		@${REINPLACE_CMD} -e 's:INSTALL) -D:INSTALL):' \
			${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e 's:/bin/bash:/bin/sh:' \
			-e 's:x86_64:amd64:' \
			-e 's:i686:i386:' \
			-e 's:-t \([^ ]*\) \([^ ]*\):\2 \1:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile
		@${REINPLACE_CMD} -e 's:3\.79:4.*:' \
			${WRKDIR}/glibc-${GLIBCVERSION}/configure
		@${REINPLACE_CMD} -e 's:#ifndef __u_char_defined:#if 0:' \
			-e 's:#ifndef __daddr_t_defined:#if 0:' \
			${WRKDIR}/glibc-${GLIBCVERSION}/sunrpc/rpc/types.h
		@${REINPLACE_CMD} -e 's:^\([[:space:]]*\)sed :\1gsed :' \
			${WRKDIR}/glibc-${GLIBCVERSION}/Makerules

pre-configure:
		# Linux headers
		cd ${WRKDIR}/linux-${LINUXVERSION}; \
		${MAKE_CMD} V=1 HOSTCC=${CC} ARCH=${LINUXARCH} \
			INSTALL_HDR_PATH=${GNUCROSSDIR} headers_install; \
		# Binutils
		cd ${WRKDIR}/binutils-build; \
		CC=${CC} CXX=${CXX} ../binutils-${BINUTILSVERSION}/configure \
			--target=${LINUXTRIPLET} \
			--prefix=${WRKDIR}/gnuroot \
			--disable-multilib --disable-nls; \
		${MAKE_CMD} ${_MAKE_JOBS} && \
		${MAKE_CMD} install
		# GCC compiler
		cd ${WRKDIR}/gcc-build; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		CC=${CC} CXX=${CXX} ../gcc-${GCCVERSION}/configure \
			--target=${LINUXTRIPLET} \
			--prefix=${WRKDIR}/gnuroot \
			--enable-languages=c,c++ --disable-multilib; \
		${MAKE_CMD} ${_MAKE_JOBS} all-gcc && \
		${MAKE_CMD} install-gcc
		# Glibc headers / startup code
		cd ${WRKDIR}/glibc-build; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		export nargs=0; \
		BUILD_CC=${CC} CC=${LINUXTRIPLET}-gcc \
		../glibc-${GLIBCVERSION}/configure \
			--host=${LINUXTRIPLET} \
			--prefix=${GNUCROSSDIR} \
			--with-binutils=${WRKDIR}/gnuroot/bin \
			--with-headers=${GNUCROSSDIR}/include \
			--disable-profile --disable-multilib \
			--enable-kernel=2.6.32 libc_cv_forced_unwind=yes \
			libc_cv_ssp=no; \
		${MAKE_CMD} install-bootstrap-headers=yes install-headers; \
		${MAKE_CMD} ${_MAKE_JOBS} csu/subdir_lib; \
		${INSTALL_DATA} csu/crt1.o csu/crti.o csu/crtn.o \
			${GNUCROSSDIR}/lib; \
		${LINUXTRIPLET}-gcc -nostdlib -nostartfiles -shared \
			-x c /dev/null -o ${GNUCROSSDIR}/lib/libc.so; \
		${TOUCH} ${GNUCROSSDIR}/include/gnu/stubs.h
		# GCC support libs
		cd ${WRKDIR}/gcc-build; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		${MAKE_CMD} ${_MAKE_JOBS} all-target-libgcc; \
		${MAKE_CMD} install-target-libgcc
		# Glibc library
		cd ${WRKDIR}/glibc-build; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		${MAKE_CMD} ${_MAKE_JOBS}; \
		${MAKE_CMD} install
		# GCC libstdc++
		${ECHO_CMD} '#/bin/sh\ntrue' \
			>${WRKDIR}/gnuroot/bin/ldconfig
		${CHMOD} +x ${WRKDIR}/gnuroot/bin/ldconfig
		cd ${WRKDIR}/gcc-build; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		${MAKE_CMD} ${_MAKE_JOBS}; \
		${MAKE_CMD} install
		# FDK AAC
		cd ${WRKDIR}/fdk-aac-${FDKAACVERSION}; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		export CXXFLAGS="${CFLAGS}"; \
		LDFLAGS=-L${WRKDIR}/gnuroot/lib \
		./configure --prefix=${WRKDIR}/gnuroot \
			--disable-shared --enable-static --with-pic \
			--host=${LINUXTRIPLET} --disable-silent-rules; \
		${MAKE_CMD} ${_MAKE_JOBS} install
		# ffmpeg
		cd ${WRKDIR}/ffmpeg-${FFMPEGVERSION}; \
		export PATH=${WRKDIR}/gnuroot/bin:$$PATH; \
		export CFLAGS="${CFLAGS}"; \
		PKG_CONFIG_PATH=${WRKDIR}/gnuroot/lib/pkgconfig \
		CPPFLAGS="-Dcaddr_t=void\* -D__daddr_t_defined" \
		LDFLAGS=-L${WRKDIR}/gnuroot/lib \
		./configure --prefix=${WRKDIR}/gnuroot \
			--disable-shared --enable-static --enable-pic \
			--enable-libfdk-aac --pkg-config=pkg-config \
			--cross-prefix=${LINUXTRIPLET}- --arch=${LINUXARCH} \
			--target-os=linux --host-cc=${CC}; \
		CFLAGS="${CFLAGS}" \
		${MAKE_CMD} ${_MAKE_JOBS} V=1 ARCH=x86 all install
		# OpenSSL headers
		cd ${WRKDIR}/openssl-${OPENSSLFULLVER}; \
		./Configure --openssldir= --prefix=/usr ${OPENSSLTARGET}

do-configure:
		cd ${WRKSRC}; \
		CC=${LINUXTRIPLET}-gcc CXX=${LINUXTRIPLET}-g++ \
		CFLAGS="${CFLAGS:N-Wl,-rpath=*}" \
		CXXFLAGS="${CXXFLAGS:N-Wl,-rpath=*}" \
		LDFLAGS="${LDFLAGS:N-Wl,-rpath=*}" \
		PATH=${WRKDIR}/gnuroot/bin:${PATH} \
		PKG_CONFIG_PATH=${WRKDIR}/gnuroot/lib/pkgconfig \
		./configure --prefix=${PREFIX} --host=${LINUXTRIPLET} \
			--libdir=${PREFIX}/lib/makemkv --disable-gui

pre-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/makemkv

post-install:
		${INSTALL_MAN} ${FILESDIR}/makemkvcon.1 \
			${STAGEDIR}${PREFIX}/man/man1
		${INSTALL_LIB} ${GNUCROSSLIBDIR}/libstdc++.so.6 \
			${STAGEDIR}${PREFIX}/lib/makemkv
		cd ${WRKDIR}/makemkv-bin-${PORTVERSION}; \
		${MKDIR} tmp; \
		${ECHO_CMD} accepted > tmp/eula_accepted; \
		${MAKE_CMD} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} install
		${PATCHELF_CMD} --set-rpath ${PREFIX}/lib/makemkv \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		${REINPLACE_CMD} -e 's:/sys/bus/scsi:/etc/makemkv/:' \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		${INSTALL_SCRIPT} ${WRKDIR}/update-makemkv-drives \
			${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
