# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# heavily modified by: Matthias Andree <mandree@FreeBSD.org>
#
# supported FLAVORS=	default nobootfsck roothardlinks
# FLAVORS explained:
# default 	- install e2fsck fsck_ext2fs into /sbin and symlink from PREFIX
# 		- requires that / is writable
#
# roothardlinks - install e2fsck fsck_ext2fs into /sbin and hardlink from PREFIX
# 		- requires that / is writable and the same file system as PREFIX
#
# nobootfsck	- does not install into /sbin, but will be unable to fsck
# 		  ext2/ext3/ext4 file systems at boot, before PREFIX is mounted

PORTNAME=	e2fsprogs
PORTVERSION=	1.46.5
PORTREVISION?=	1
CATEGORIES?=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/kernel/people/tytso/${PORTNAME}/v${PORTVERSION}

MAINTAINER?=	mandree@FreeBSD.org
COMMENT?=	Utilities & library to manipulate ext2/3/4 filesystems

LICENSE?=	GPLv2+
.if !defined(_no_license_file)
LICENSE_FILE?=	${WRKSRC}/NOTICE
.endif
LICENSE_DISTFILES_GPLv2+ =	${DISTNAME}${EXTRACT_SUFX}

USES=		cpe gmake makeinfo pkgconfig tar:xz
CPE_VENDOR=	e2fsprogs_project
USE_CSTD=	gnu99
# this seems a bit redundant to the --rpath below, but
# the latter should be more robust in case someone needs
# to deal with the file systems from a system not yet fully booted.
.if !defined(PKGNAMESUFFIX)
USE_LDCONFIG=	${PREFIX}/lib/e2fsprogs
.endif
GNU_CONFIGURE=	yes

# while we use the system blkid, we need to --enable-libblkid
# so that the tools get built:
CONFIGURE_ARGS?=--disable-fsck \
		--disable-e2initrd-helper \
		--disable-libuuid \
		--disable-uuidd \
		--enable-libblkid \
		--enable-elf-shlibs \
		--libdir='${PREFIX}/lib/e2fsprogs/' \
		--includedir='${PREFIX}/include/e2fsprogs/' \
		--with-root-prefix='${PREFIX}' \
		LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib -Wl,--rpath -Wl,${LOCALBASE}/lib/e2fsprogs'
CONFIGURE_ENV?=	LIBS='-Wl,--as-needed ${LIBS} -lexecinfo -lelf'
# apparently HAVE_PTHREAD_H checks go missing if the FUSEFS option is unset, force it:
CPPFLAGS+=	-I${WRKSRC}/lib -I${LOCALBASE}/include # -D_EXT2_USE_C_VERSIONS
MAKE_ARGS+=	pkgconfigdir='${PREFIX}/libdata/pkgconfig'
MAKE_ENV+=	CHECK_CMD=@true

CONFLICTS_INSTALL=	e2fsprogs e2fsprogs-nobootfsck e2fsprogs-roothardlinks

PORTSCOUT=	ignore:1	# cannot handle the version in the directory

.if !defined(MASTERDIR)
CPPFLAGS+=	-D__GNUC_PREREQ\(a,b\)=1

INSTALL_TARGET=		install install-libs

OPTIONS_DEFINE=		DOCS NLS FUSEFS PARALLELTESTS SLOWTESTS BASHTESTS LIBUNWIND
OPTIONS_EXCLUDE+=	EXAMPLES
OPTIONS_SUB=		yes

OPTIONS_SINGLE=			SELFTEST
OPTIONS_SINGLE_SELFTEST=	NOTESTS SMALLTESTS ALLTESTS
OPTIONS_DEFAULT=		SMALLTESTS
FUSEFS_DESC=	Build user-land ext2/3/4 FUSE module (slow!)
SELFTEST_DESC=	Choose which set of self-tests to run
NOTESTS_DESC=	Do not run any self-tests (Tier-1, DISCOURAGED)
SMALLTESTS_DESC=Run tests that need <500 MB disk space (DEFAULT)
ALLTESTS_DESC=	Run most self-tests (needs more RAM/disk space)
PARALLELTESTS_DESC=	Parallelize self-tests (needs more disk space)
SLOWTESTS_DESC=	Enable slow tests that are skipped by default
BASHTESTS_DESC=	Enable tests that require the GNU bash shell
LIBUNWIND_DESC=	Backtrace with libunwind (do set WITH_DEBUG_PORTS+=${PKGORIGIN}!)

FUSEFS_CONFIGURE_ENABLE=	fuse2fs

BUILD_DEPENDS+=	gdd:sysutils/coreutils
BASHTESTS_BUILD_DEPENDS=	${BASH_CMD}:shells/bash
BASH_CMD=	${LOCALBASE}/bin/bash

LIB_DEPENDS+=	libblkid.so:misc/e2fsprogs-libblkid
LIB_DEPENDS+=	libuuid.so:misc/e2fsprogs-libuuid

LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_LIBS+=	-L${LOCALBASE}/lib -lunwind
LIBUNWIND_LDFLAGS+=	-rdynamic
LIBUNWIND_EXTRA_PATCHES=${FILESDIR}/extrapatch-e2fsck_sigcatcher.c

PORTDOCS=	NOTICE README RELEASE-NOTES SUBMITTING-PATCHES
.endif

# even under DEVELOPER, no REINPLACE_CMD warnings desired
# it simply makes no sense to warn about dozens of files
# for systematic edits that run over files that don't need the edits.
# a "warn if nothing was edited by one command" would be acceptable,
# but until we have that in the framework, just
# avoid Tools/scripts/sed_checked altogether:
REINPLACE_CMD=	${SED} ${REINPLACE_ARGS}

PKGDEINSTALL=	${PKGINSTALL}

MAKE_ARGS+=	V=1

.include <bsd.port.options.mk>

.if ${MASTERDIR} == ${.CURDIR}
FLAVORS=	default nobootfsck roothardlinks
FLAVOR?=	${FLAVORS:[1]}
nobootfsck_PKGNAMESUFFIX=	-nobootfsck
roothardlinks_PKGNAMESUFFIX=	-roothardlinks
.endif

. if ! empty(ARCH:Mpowerpc*)
# Fix powerpc64/powerpc SIGSEGV,
# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=231570 (ppc64)
# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242798 (ppc32 - untested)
USES+=		compiler:c11
. endif

.if ${PORT_OPTIONS:MFUSEFS}
USES+=		fuse
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv:build
.endif

.if empty(PORT_OPTIONS:MNOTESTS) && ${MASTERDIR} == ${.CURDIR}
USES+=		perl5
USE_PERL5=	build
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
. if empty(ICONV_LIB)
libintl=	${LOCALBASE}/lib/libintl.a
. else
libintl=	${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a
. endif
.else
CONFIGURE_ARGS+=--disable-nls
libintl=
.endif

.if ${MASTERDIR} == ${.CURDIR} && (${ARCH} == "aarch64" || ${ARCH} == "riscv64")
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-no-sbrk
.endif

# d_fallocate_blkmap appears to fail on some systems for unknown reasons.
post-patch::
	@${REINPLACE_CMD} -E -e 's/md5sum ([^ ]*)/printf "%s  %s\\n" $$(md5 -q \1) \1/' \
	    -e "s/ == 0/ = 0/" -e "s/tar x$$/tar xf -/" -e "s/\<dd\>/gdd/" \
	    ${WRKSRC}/tests/[a-z]_*/script
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' ${WRKSRC}/*/*.c
	@${REINPLACE_CMD} -e 's,/etc/blkid.tab,${ETCDIR}/blkid.tab,' ${WRKSRC}/misc/blkid* ${WRKSRC}/lib/blkid/blkidP.h
	@${REINPLACE_CMD} -E -e 's/__GNUC_PREREQ\>/__GNUC_PREREQ__/' ${WRKSRC}/*/*/*.[ch] ${WRKSRC}/*/*.c
.if empty(PORT_OPTIONS:MALLTESTS)
. for i in \
		d_fallocate_blkmap \
		f_baddir \
		f_bbfile \
		f_convert_bmap \
		f_detect_junk \
		f_inode_ea_collision \
		f_lpffile \
		f_no_cache_corrupt_inode \
		f_opt_extent \
		j_corrupt_descr_csum \
		m_bigjournal \
		m_hugefile_slack \
		m_offset \
		m_raid_opt \
		r_32to64bit \
		r_32to64bit_expand_full \
		r_32to64bit_meta \
		r_32to64bit_move_itable \
		r_64to32bit \
		r_64to32bit_meta \
		r_expand_full \
		r_min_itable \
		t_change_uuid_mounted \
		t_dangerous \
		t_disable_changed_csum_seed_mounted \
		t_disable_mcsum \
		t_disable_mcsum_noinitbg \
		t_disable_mcsum_yesinitbg \
		t_enable_mcsum \
		t_enable_mcsum_initbg \
		t_iexpand_full \
		t_iexpand_mcsum \
		t_uninit_bg_rm \
		u_dryrun \
		u_mke2fs_opt_offset
	@${MV} ${WRKSRC}/tests/${i} ${WRKSRC}/tests/disabled_test-${i}
. endfor
.endif
.if ${PORT_OPTIONS:MBASHTESTS}
	${REINPLACE_CMD} -e 's}^SHELL *=.*}SHELL = ${_CHECK_SHELL}}' ${WRKSRC}/MCONFIG.in
.else
. for i in f_large_dir
	@${MV} ${WRKSRC}/tests/${i} ${WRKSRC}/tests/disabled_test-${i}
. endfor
.endif

##############################################################
# Master port stuff that is not to be seen by the slave ports.
##############################################################
.if ${MASTERDIR} == ${.CURDIR}
# NOTE: The previous .if block goes all the way to the end of the file.

.if ${FLAVOR} == nobootfsck
PLIST_SUB+=	ROOTSBIN="@comment "
.else
PLIST_SUB+=	ROOTSBIN=""
.endif

.if !empty(PORT_OPTIONS:MNOTESTS) && (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1400000 || ((${ARCH} != i386) && (${ARCH} != amd64)))
BROKEN=	it was not tested on your system by the maintainer; you must run self-tests
.endif

pre-build:
# fix up Makefile ordering for parallel builds
	cd ${WRKSRC}/lib/et && ${DO_MAKE_BUILD} compile_et
	cd ${WRKSRC}/lib/ss && _ET_DIR_OVERRIDE=../et ../et/compile_et ss_err.et \
		&& ${REINPLACE_CMD} -f ${FILESDIR}/fix-ss_err.h.sed ss_err.h
	cd ${WRKSRC}/lib/support && ${DO_MAKE_BUILD} prof_err.h

.if ${PORT_OPTIONS:MPARALLELTESTS}
_CHECK_JOBS=${_MAKE_JOBS}
.else
_CHECK_JOBS=
.endif

_checkaddargs=
.if ${PORT_OPTIONS:MBASHTESTS}
_CHECK_SHELL=${LOCALBASE}/bin/bash
_checkaddargs+=--eval SHELL:=${BASH_CMD}
.else
_CHECK_SHELL=${SH}
.endif

.if !defined(TMPDIR)
_checkaddargs+=TMPDIR=${WRKDIR}/tmp
.endif

.if ${PORT_OPTIONS:MSLOWTESTS}
_check_target=SKIP_SLOW_TESTS= check
_check_timeout=7200
.else
_check_target=check
_check_timeout=180
.endif

.if ${PORT_OPTIONS:MLIBUNWIND}
_staticlibs+=${LOCALBASE}/lib/libunwind.a /usr/lib/liblzma.a /usr/lib/libmd.a
.endif

post-build:
# Relink e2fsck statically - We need to make sure that tools for the root file
# system are statically linked against anything that is outside the root fs,
# else we're in trouble if e2fsck is needed for boot:
# (we don't use e2fsck.static, since we can link libc.so dynamically)
# NOTE: we need to link libgcc statically, it might be under /usr/local!
# => do not add a -Bdynamic - but instead list the dynamic libraries
# before the -Bstatic
	cd ${WRKSRC}/e2fsck && ${RM} -f e2fsck \
		&& ${MAKE_CMD} e2fsck V=1 \
		LIBS="-static-libgcc -lc -Bstatic ../lib/libsupport.a ../lib/libext2fs.a ../lib/libcom_err.a \
		${_staticlibs} /usr/lib/libexecinfo.a /usr/lib/libelf.a \
		${LOCALBASE}/lib/libblkid.a ${LOCALBASE}/lib/libuuid.a ${libintl} ../lib/libe2p.a " \
		&& ${STRIP_CMD} e2fsck
# Regression check: avoid a port (not upstream!) regression from 1.40.5,
# check that e2fsck isn't dynalinked against anything but libc.so:
	@${ECHO_CMD} -n "===>  checking that e2fsck depends on no shared objects outside /lib: "
	@a="$$(ldd ${WRKSRC}/e2fsck/e2fsck 2>/dev/null \
	    | ${GREP} -v 'not a dynamic executable' \
	    | ${GREP} '=>' \
	    | ${AWK}  '{print $$3;}' \
	    | ${EGREP} -v '^/lib/lib.*\.so\.' || :)"; \
	if test "x$$a" = "x" ; then echo 'PASS' ; else \
	    echo 'FAIL' ; echo '===>  e2fsck depends on:' ; echo "$$a" ; exit 1 ; fi
# Update translation binary files
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po && ${MAKE_CMD} update-gmo
.endif
# Build fsck(8) wrapper
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -s ${LIBS} \
		-o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c
# While the ${MAKE} check can take a minute on an end user's system, the
# correctness of tools such as e2fsck is critical to the health of the
# file systems.  The upstream is not using any *BSD as his development
# system, and therefore let's exercise due diligence in running the self-
# test on each and every system and not just package building hosts.
# There have been subtle failures induced by Linux-isms in the past.
# -- Matthias Andree, package maintainer, 2007-09-18
.if empty(PORT_OPTIONS:MNOTESTS)
	@${ECHO_CMD} '===>  Running e2fsprogs self-test suite'
# do not add -j options unconditionally to ${MAKE_CMD} below, this might break
# due to excessive disk space use.
	cd ${WRKSRC}/tests && \
		ulimit -t ${_check_timeout} && \
		${MKDIR} ${WRKDIR}/tmp && \
		${SETENV} e2fsprogs_inhibit_SIGINFO=1 BLKID_FILE=${WRKDIR}/tmp/blkid.tab SHELL=${_CHECK_SHELL} \
		${MAKE_CMD} ${_check_target} ${_CHECK_JOBS} ${_checkaddargs} \
	    || { head -n30000 ${WRKSRC}/tests/*.failed 2>/dev/null ; exit 1 ; }
.else
	@${ECHO_CMD} '===>  SKIPPING e2fsprogs self-test suite (DISCOURAGED!)'
.endif

post-install:
	# pkg workaround time again;
	# the whole purpose of this dance is to move the necessities for
	# /etc/fstab fsck'ing into /sbin, and symlink to these guys
	# in the regular hierarchy, normally $PREFIX/sbin. Hard links may
	# crash the install if /usr[/local] is a separate file system from /,
	# and pkg 1.15.4 can't automatically unroll or install relative symlinks.
.if ${FLAVOR} != nobootfsck
	${MKDIR} ${STAGEDIR}/sbin
	${MV} -f ${STAGEDIR}${PREFIX}/sbin/e2fsck ${STAGEDIR}/sbin/ # from INSTALL_TARGET
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${STAGEDIR}/sbin/  # from port
	# according to TPH 6.1.1 Handling Symbolic Links, these are to be absolute
	# for the default FLAVOR, yet stage-qa warns about these on 2020-09-16.
. if ${FLAVOR} == roothardlinks
	${LN} -f ${STAGEDIR}/sbin/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
	${LN} -f ${STAGEDIR}/sbin/e2fsck      ${STAGEDIR}${PREFIX}/sbin/
. else
	${LN} -fs /sbin/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
	${LN} -fs /sbin/e2fsck      ${STAGEDIR}${PREFIX}/sbin/
. endif
.else
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
.endif
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext2
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext3
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext4
	# now the remainder of the usual post-install jobs:
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${STAGEDIR}${PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	# remove or relocate files installed by other ports already, or shadowing system files:
	cd ${STAGEDIR}${PREFIX} && \
		${XARGS} <${FILESDIR}/unwanted ${RM} && \
		${RMDIR} include/e2fsprogs/blkid
	${MV} ${STAGEDIR}${PREFIX}/bin/compile_et ${STAGEDIR}${PREFIX}/bin/e2fsprogs-compile_et
	${MV} ${STAGEDIR}${MANPREFIX}/man/man1/compile_et.1 ${STAGEDIR}${MANPREFIX}/man/man1/e2fsprogs-compile_et.1
	${MKDIR} ${STAGEDIR}${DATADIR}/et/
	${MV} ${STAGEDIR}${PREFIX}/share/et/* ${STAGEDIR}${DATADIR}/et/
	${REINPLACE_CMD} -e 's}^DIR=.*$$}DIR=${DATADIR}/et}' -i '' ${STAGEDIR}${PREFIX}/bin/e2fsprogs-compile_et
	${RMDIR} ${STAGEDIR}${PREFIX}/share/et
	${MV} -f ${STAGEDIR}${MANPREFIX}/man/man3/com_err.3 \
		 ${STAGEDIR}${MANPREFIX}/man/man3/e2fsprogs-com_err.3

#
# the next line closes .if ${MASTERDIR} == ${.CURDIR}
.endif

.include <bsd.port.post.mk>
