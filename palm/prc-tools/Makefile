# New ports collection makefile for:	Palm OS PRC-tools
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prc-tools
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} ${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	prc-tools binutils/releases \
		gcc/releases/gcc-2.95.3 gdb/old-releases gcc/releases/gcc-3.3.1
DISTNAME=	prc-tools-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		binutils-2.14.tar.bz2 gdb-5.3.tar.bz2 gcc-2.95.3.tar.bz2 \
		gcc-3.3.1.tar.bz2
EXTRACT_ONLY=	binutils-2.14.tar.bz2 gdb-5.3.tar.bz2 gcc-2.95.3.tar.bz2 \
		gcc-3.3.1.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of tools supporting C and C++ programming for Palm OS

BUILD_DEPENDS=	${LOCALBASE}/bin/autoheader:${PORTSDIR}/devel/autoconf

BROKEN=		"Incorrect pkg-plist"

# it is unknown whether it could actually be made to work elsewhere,
# but right now it does not.
ONLY_FOR_ARCHS=	i386

USE_BZIP2=	YES
USE_BISON=	YES
USE_GMAKE=	YES
PREFIX=		${LOCALBASE}/pilot
WRKSRC=		${WRKDIR}/build
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../prc-tools-${PORTVERSION}/configure
CONFIGURE_ARGS=	--enable-targets=m68k-palmos,arm-palmos \
		--enable-languages=c,c++ \
		--sharedstatedir=${LOCALBASE}/palmdev --prefix=${PREFIX} \
		--with-headers=${WRKSRC}/empty --disable-nls
CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/bin
MAKE_ENV=	PATH=${PATH}:${PREFIX}/bin
MAN1=		cccp.1 m68k-palmos-g++.1 m68k-palmos-gcc.1 \
		m68k-palmos-addr2line.1 m68k-palmos-ar.1 \
		m68k-palmos-as.1 m68k-palmos-c++filt.1 \
		m68k-palmos-ld.1 m68k-palmos-nlmconv.1 \
		m68k-palmos-nm.1 m68k-palmos-objcopy.1 \
		m68k-palmos-objdump.1 m68k-palmos-ranlib.1 \
		m68k-palmos-size.1 m68k-palmos-strings.1 \
		m68k-palmos-strip.1 m68k-palmos-dlltool.1 \
		m68k-palmos-readelf.1 m68k-palmos-windres.1 \
		m68k-palmos-gdb.1 build-prc.1 palmdev-prep.1 \
		arm-palmos-addr2line.1 arm-palmos-ar.1 \
		arm-palmos-as.1 arm-palmos-c++filt.1 \
		arm-palmos-dlltool.1 arm-palmos-g++.1 \
		arm-palmos-gcc.1 arm-palmos-ld.1 \
		arm-palmos-nlmconv.1 arm-palmos-nm.1 \
		arm-palmos-objcopy.1 arm-palmos-objdump.1 \
		arm-palmos-ranlib.1 arm-palmos-readelf.1 \
		arm-palmos-size.1 arm-palmos-strings.1 \
		arm-palmos-strip.1 arm-palmos-windres.1 \
		cpp.1 gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

.include <bsd.port.pre.mk>

CFLAGS:=	${CFLAGS:C/-m[-=0-9a-z]*//g}

post-extract:
	@(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS})

pre-patch:
	${MKDIR} ${WRKSRC}/empty

post-patch:
	@(cd ${WRKDIR} && \
	 ${CAT}	prc-tools-${PORTVERSION}/binutils-2.14.palmos.diff \
		prc-tools-${PORTVERSION}/gdb-5.3.palmos.diff \
		prc-tools-${PORTVERSION}/gcc-2.95.3.palmos.diff \
		prc-tools-${PORTVERSION}/gcc-3.3.1.palmos.diff | ${PATCH} -p0)
	@${MV} ${WRKDIR}/gcc-2.95.3/gcc/config/i386/freebsd.h ${WRKDIR}/gcc-2.95.3/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKDIR}/gcc-2.95.3/gcc/config/i386/freebsd-elf.h ${WRKDIR}/gcc-2.95.3/gcc/config/i386/freebsd.h
	@${MV} ${WRKDIR}/gcc-2.95.3/libstdc++/stl/stl_bvector.h \
		${WRKDIR}/gcc-2.95.3/libstdc++/stl/stl_bvector.h.orig
	@${SED} -e "s,_WORD_BIT,_WORD_BIT_GCC295,g" \
		< ${WRKDIR}/gcc-2.95.3/libstdc++/stl/stl_bvector.h.orig \
		> ${WRKDIR}/gcc-2.95.3/libstdc++/stl/stl_bvector.h
	@(cd ${WRKDIR}/gcc-2.95.3; \
	 PATCHES_APPLIED="" ; \
	 for i in ${PORTSDIR}/lang/gcc295/files/patch-*; do \
		if ${PATCH} -p0 --forward --quiet -E < $$i; then \
			PATCHES_APPLIED="$$PATCHES_APPLIED $$i"; \
		else \
			${ECHO_MSG} `${ECHO_CMD} ">> Patch $$i failed to apply cleanly."` ; \
		fi; \
	 done)
	@(cd ${WRKDIR}/gcc-3.3.1; \
	 PATCHES_APPLIED="" ; \
	 for i in ${PORTSDIR}/lang/gcc33/files/patch-*; do \
		if ${PATCH} -p0 --forward --quiet -E < $$i; then \
			PATCHES_APPLIED="$$PATCHES_APPLIED $$i"; \
		else \
			${ECHO_MSG} `${ECHO_CMD} ">> Patch $$i failed to apply cleanly."` ; \
		fi; \
	 done)
	@cd ${WRKDIR}/gcc-2.95.3 && ${PATCH} -p0 --forward --quiet -E < ${FILESDIR}/post-patch-gcc:strerror.c
	@cd ${WRKDIR}/gcc-3.3.1 && ${PATCH} -p0 --forward --quiet -E < ${FILESDIR}/post-patch-gcc:Makefile.in

pre-configure:
	(cd ${WRKDIR}/prc-tools-${PORTVERSION} && \
	 ${LN} -sf ../binutils-2.14 binutils; \
	 ${LN} -sf ../gdb-5.3 gdb; \
	 ${LN} -sf ../gcc-2.95.3 gcc295; \
	 ${LN} -sf ../gcc-3.3.1 gcc; )

post-install:
	${RM} ${PREFIX}/bin/m68k-palmos-c++filt
	${RM} ${PREFIX}/lib/libiberty.a
	${RM} -f ${PREFIX}/m68k-palmos/sys-include/COPIED
	${RM} -f ${PREFIX}/arm-palmos/sys-include/COPIED

.include <bsd.port.post.mk>
