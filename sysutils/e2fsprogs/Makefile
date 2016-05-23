# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e2fsprogs
PORTVERSION=	1.42.13
PORTREVISION?=	0
CATEGORIES?=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/kernel/people/tytso/${PORTNAME}/v${PORTVERSION}

MAINTAINER?=	mandree@FreeBSD.org
COMMENT?=	Utilities & library to manipulate ext2/3/4 filesystems

LICENSE=	GPLv2

PORTSCOUT=	ignore	# cannot handle the version in the directory

USES=		cpe gmake pkgconfig tar:xz
CPE_VENDOR=	e2fsprogs_project
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-fsck --disable-e2initrd-helper \
		--enable-quota \
		--with-root-prefix='${PREFIX}'
CPPFLAGS+=	-I${WRKSRC}/lib -I${LOCALBASE}/include # -D_EXT2_USE_C_VERSIONS
MAKE_ARGS+=	LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib' pkgconfigdir='${PREFIX}/libdata/pkgconfig'
MAKE_ENV+=	CHECK_CMD=@true

.if !defined(MASTERDIR)
OPTIONS_DEFINE=		DOCS NLS
OPTIONS_EXCLUDE+=	EXAMPLES

PORTDOCS=	COPYING RELEASE-NOTES

post-extract:
	@${CHMOD} u+w ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

PKGDEINSTALL=	${PKGINSTALL}

# get more details into tinderbox logs
.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	V=1
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv:build
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB=	NLS=""
. if empty(ICONV_LIB)
libintl=	"${LOCALBASE}/lib/libintl.a"
. else
libintl=	"${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
. endif
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
libintl=
.endif

post-patch::
# don't build/install libext2fs.info
	@${REINPLACE_CMD} -e 's/ install-doc-libs$$//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's/md5sum ([^ ]*)/printf "%s  %s\\n" $$(md5 -q \1) \1/' \
	    -e "s/ == 0/ = 0/" ${WRKSRC}/tests/[a-t]_*/script
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' ${WRKSRC}/*/*.c
# disable f_mmp_garbage, fails on FreeBSD, and the resize*big_expand tests,
# which are too unwieldy to run automatically (need too much free space).
# f_extent_oobounds appears to have differences in screen output, reason
# unclear.
.for i in f_mmp_garbage m_bigjournal r_64bit_big_expand r_bigalloc_big_expand r_ext4_big_expand f_extent_oobounds
	@${MV} ${WRKSRC}/tests/${i} ${WRKSRC}/tests/disabled_test-${i}
.endfor

.if ${MASTERDIR} == ${.CURDIR}
pre-build:
# fix up Makefile ordering for parallel builds
	cd ${WRKSRC}/lib/et && ${DO_MAKE_BUILD} compile_et
	cd ${WRKSRC}/e2fsck && ${DO_MAKE_BUILD} prof_err.h

post-build:
# Relink e2fsck statically - We need to make sure that tools for the root file
# system are statically linked against anything that is outside the root fs,
# else we're in trouble if e2fsck is needed for boot:
# (we don't use e2fsck.static, since we can link libc.so dynamically)
	cd ${WRKSRC}/e2fsck && ${RM} -f e2fsck \
		&& ${MAKE_CMD} e2fsck \
		STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a \
		../lib/libblkid.a  ../lib/libuuid.a" \
		LIBINTL=${libintl}
# Regression check: avoid a port (not upstream!) regression from 1.40.5,
# check that e2fsck isn't dynalinked against anything but libc.so:
	@${ECHO_CMD} -n "===>  checking that e2fsck depends on no shared objects beyond libc and libgcc: "
	@a="$$(ldd ${WRKSRC}/e2fsck/e2fsck 2>/dev/null \
	    | ${GREP} -v 'not a dynamic executable' \
	    | ${GREP} '=>' \
	    | ${AWK}  '{print $$3;}' \
	    | ${EGREP} -v '^/lib/libgcc(_s)?\.so\.' \
	    | ${GREP} -v '^/lib/libc\.so\.' || :)"; \
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
	@${ECHO_CMD} '===>  Running e2fsprogs self-test suite'
# do not add -j options to ${MAKE_CMD} below, this might break
# due to excessive disk space use.
	cd ${WRKSRC}/tests && ${MKDIR} ${WRKDIR}/tmp && ${MAKE_CMD} check TMPDIR=${WRKDIR}/tmp \
	    || { head -n30000 ${WRKSRC}/tests/*.failed 2>/dev/null ; exit 1 ; }

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/sbin/uuidd
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${STAGEDIR}${PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
# the next line closes .if ${MASTERDIR} == ${.CURDIR}
.endif

.include <bsd.port.post.mk>
