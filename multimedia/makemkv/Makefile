# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	makemkv
PORTVERSION=	1.16.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.makemkv.com/download/:makemkv \
		http://www.makemkv.com/download/old/:makemkv \
		SF/opencore-amr/fdk-aac/:fdkaac \
		https://ffmpeg.org/releases/:ffmpeg \
		https://www.openssl.org/source/old/${OPENSSLVERSION}/:openssl
DISTFILES=	makemkv-oss-${PORTVERSION}.tar.gz:makemkv \
		makemkv-bin-${PORTVERSION}.tar.gz:makemkv \
		fdk-aac-${FDKAACVERSION}.tar.gz:fdkaac \
		ffmpeg-${FFMPEGVERSION}.tar.bz2:ffmpeg \
		openssl-${OPENSSLFULLVER}.tar.gz:openssl
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	felix@palmen-it.de
COMMENT=	Video converter reading from DVD and Bluray

LICENSE=	MAKEMKV FDK LGPL21+ OpenSSL
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
LICENSE_DISTFILES_LGPL21+ =	ffmpeg-${FFMPEGVERSION}.tar.bz2
LICENSE_DISTFILES_OpenSSL=	openssl-${OPENSSLFULLVER}.tar.gz
LICENSE_DISTFILES_MAKEMKV=	makemkv-bin-${PORTVERSION}.tar.gz \
				makemkv-oss-${PORTVERSION}.tar.gz

ONLY_FOR_ARCHS=	amd64 i386
USES=	gmake linux pkgconfig perl5
USE_LINUX=	base expat expat:build openssl openssl:build devtools:build
USE_PERL5=	build
BUILD_DEPENDS=	nasm>0:devel/nasm \
		${LOCALBASE}/include/expat.h:textproc/expat2 \
		patchelf>0:sysutils/patchelf

NO_CDROM=	Do not sell
RESTRICTED_FILES=	makemkv-bin-${PORTVERSION}.tar.gz
LEGAL_TEXT=	${NO_CDROM}. Do not redistribute modified binaries, but\
		explicit permission to distribute a patched makemkvcon given\
		by copyright owner

WRKSRC=		${WRKDIR}/makemkv-oss-${PORTVERSION}

SUB_FILES=	update-makemkv-drives
SUB_LIST=	LINUXBASE=${LINUXBASE}
PLIST_SUB=	LINUXBASE=${LINUXBASE}

FDKAACVERSION=	2.0.1
FFMPEGVERSION=	4.3.2
OPENSSLVERSION=	1.0.2
OPENSSLPATCHLEVEL=	k
OPENSSLFULLVER=	${OPENSSLVERSION}${OPENSSLPATCHLEVEL}

LINUXARCH=	${ARCH:S/amd64/x86_64/}
LINUXTRIPLET=	${LINUXARCH}-redhat-linux
LINUXLIBDIR=	${LINUXBASE}/${"${LINUXARCH:Mx86_64}" != "":?lib64:lib}
OPENSSLTARGET=	${"${LINUXARCH:Mx86_64}" != "":?linux-x86_64:linux-elf}

PATCHELF_CMD?=	${LOCALBASE}/bin/patchelf

CFLAGS+=	-std=c++11 -DFORCE_OPENSSL_NO_EC -I${WRKDIR}/gnuroot/include \
		-I${WRKDIR}/openssl-${OPENSSLFULLVER}/include
SSP_CFLAGS=
LDFLAGS+=	-L${WRKDIR}/gnuroot/lib
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-gui --host=${LINUXTRIPLET} \
		--libdir=${PREFIX}/lib/makemkv
CONFIGURE_ENV=	CC=${LINUXTRIPLET}-gcc CXX=${LINUXTRIPLET}-g++ \
		PATH=${WRKDIR}/gnuroot/bin:${PATH} \
		PKG_CONFIG_PATH=${WRKDIR}/gnuroot/lib/pkgconfig
MAKE_ENV=	PATH=${WRKDIR}/gnuroot/bin:${PATH}
STRIP_CMD=	${WRKDIR}/gnuroot/bin/${LINUXTRIPLET}-strip

post-extract:
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
		@${MKDIR} ${WRKDIR}/gnuroot/bin
		@cd ${WRKDIR}/gnuroot/bin; \
		for t in gcc link ld objdump ar nm strip ranlib g++; do \
			${LN} -s ${LINUXBASE}/bin/$$t ${LINUXTRIPLET}-$$t; \
		done

post-patch:
		@${REINPLACE_CMD} -e 's:INSTALL) -D:INSTALL):' \
			${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e 's:/bin/bash:/bin/sh:' \
			-e 's:x86_64:amd64:' \
			-e 's:i686:i386:' \
			-e 's:-t \([^ ]*\) \([^ ]*\):\2 \1:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile

pre-configure:
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

pre-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/makemkv

post-install:
		${INSTALL_MAN} ${FILESDIR}/makemkvcon.1 \
			${STAGEDIR}${PREFIX}/man/man1
		cd ${WRKDIR}/makemkv-bin-${PORTVERSION}; \
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

.include <bsd.port.mk>
