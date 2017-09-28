# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e2fsprogs
PORTVERSION=	1.43.6
PORTREVISION?=	1
CATEGORIES?=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/kernel/people/tytso/${PORTNAME}/v${PORTVERSION}

MAINTAINER?=	mandree@FreeBSD.org
COMMENT?=	Utilities & library to manipulate ext2/3/4 filesystems

LICENSE?=	GPLv2+
.if !defined(_no_license_file)
LICENSE_FILE?=	${WRKSRC}/NOTICE
.endif
LICENSE_DISTFILES_GPLv2=	${DISTNAME}${EXTRACT_SUFX}

PORTSCOUT=	ignore	# cannot handle the version in the directory

.if !defined(MASTERDIR)
BROKEN_aarch64=		fails to link: missing sbrk
.endif

USES=		cpe gmake pkgconfig tar:xz
CPE_VENDOR=	e2fsprogs_project
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-fsck \
		--disable-e2initrd-helper \
		--enable-libuuid \
		--with-root-prefix='${PREFIX}'
CPPFLAGS+=	-I${WRKSRC}/lib -I${LOCALBASE}/include # -D_EXT2_USE_C_VERSIONS
MAKE_ARGS+=	LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib' pkgconfigdir='${PREFIX}/libdata/pkgconfig'
MAKE_ENV+=	CHECK_CMD=@true

.if !defined(MASTERDIR)
OPTIONS_DEFINE=		DOCS NLS FUSEFS PARALLELTESTS
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

BUILD_DEPENDS+=	gdd:sysutils/coreutils

PORTDOCS=	NOTICE README RELEASE-NOTES SUBMITTING-PATCHES
.endif

PKGDEINSTALL=	${PKGINSTALL}

MAKE_ARGS+=	V=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSEFS}
USES+=		fuse
CONFIGURE_ARGS+=--enable-fuse2fs
LDFLAGS+=	-L${LOCALBASE}/lib
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
libintl=	"${LOCALBASE}/lib/libintl.a"
. else
libintl=	"${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
. endif
.else
CONFIGURE_ARGS+=--disable-nls
libintl=
.endif

# d_fallocate_blkmap appears to fail on some systems for unknown reasons.
post-patch::
# don't build/install libext2fs.info
	@${REINPLACE_CMD} -e 's/ install-doc-libs$$//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's/md5sum ([^ ]*)/printf "%s  %s\\n" $$(md5 -q \1) \1/' \
	    -e "s/ == 0/ = 0/" -e "s/tar x$$/tar xf -/" -e "s/\<dd\>/gdd/" \
	    ${WRKSRC}/tests/[a-z]_*/script
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' ${WRKSRC}/*/*.c
.if empty(PORT_OPTIONS:MALLTESTS)
.for i in \
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
.endfor
.endif

# Master port stuff that is not to be seen by the slave ports.
.if ${MASTERDIR} == ${.CURDIR}
# NOTE: The previous .if block goes all the way to the end of the file.

.if !empty(PORT_OPTIONS:MNOTESTS) && (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1200000 || ((${ARCH} != i386) && (${ARCH} != amd64)))
BROKEN=	it was not tested on your system by the maintainer; you must run self-tests
.endif

pre-build:
# fix up Makefile ordering for parallel builds
	cd ${WRKSRC}/lib/et && ${DO_MAKE_BUILD} compile_et
	cd ${WRKSRC}/lib/support && ${DO_MAKE_BUILD} prof_err.h

.if ${PORT_OPTIONS:MPARALLELTESTS}
_CHECK_JOBS=${_MAKE_JOBS}
.else
_CHECK_JOBS=
.endif

.if !defined(TMPDIR)
_checkaddargs=TMPDIR=${WRKDIR}/tmp
.endif

post-build:
# Relink e2fsck statically - We need to make sure that tools for the root file
# system are statically linked against anything that is outside the root fs,
# else we're in trouble if e2fsck is needed for boot:
# (we don't use e2fsck.static, since we can link libc.so dynamically)
	cd ${WRKSRC}/e2fsck && ${RM} e2fsck \
		&& ${MAKE_CMD} e2fsck V=1 \
		STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a \
		../lib/libblkid.a ../lib/libuuid.a" \
		LIBINTL=${libintl} LIBMAGIC=/usr/lib/libmagic.a\ -lz
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
	cd ${WRKSRC}/tests && ulimit -t 60 && ${MKDIR} ${WRKDIR}/tmp && ${SETENV} e2fsprogs_inhibit_SIGINFO=1 BLKID_FILE=${WRKDIR}/tmp/blkid.tab ${MAKE_CMD} check ${_CHECK_JOBS} ${_checkaddargs} \
	    || { head -n30000 ${WRKSRC}/tests/*.failed 2>/dev/null ; exit 1 ; }
.else
	@${ECHO_CMD} '===>  SKIPPING e2fsprogs self-test suite (DISCOURAGED!)'
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/sbin/uuidd
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${STAGEDIR}${PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
#
# the next line closes .if ${MASTERDIR} == ${.CURDIR}
.endif

.include <bsd.port.post.mk>
