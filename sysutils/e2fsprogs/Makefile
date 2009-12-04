# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.41.9
PORTREVISION?=	0
CATEGORIES?=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER?=	mandree@freebsd.org
COMMENT?=	Utilities & library to manipulate ext2/3/4 filesystems

PATCH_STRIP=	-p1
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-fsck --disable-e2initrd-helper \
		--with-cc='${CC}' --with-linker='${LD}' \
		--with-ccopts='${CFLAGS}' \
		--with-root-prefix='${PREFIX}'
CONFIGURE_ENV+=	CPPFLAGS='${CPPFLAGS} -I${WRKSRC}/lib \
		-I${LOCALBASE}/include -D_EXT2_USE_C_VERSIONS_'
MAKE_ARGS+=	LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib'

OPTIONS=	NLS "Enable national language support" on

.if !defined(MASTERDIR)
MAN1=		chattr.1 lsattr.1
MAN5=		e2fsck.conf.5 mke2fs.conf.5
MAN8=		badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 \
		e2undo.8 mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8 \
		fsck.ext2.8 fsck.ext3.8 fsck.ext4.8 fsck.ext4dev.8 \
		mkfs.ext2.8 mkfs.ext3.8 mkfs.ext4.8 mkfs.ext4dev.8 \
		findfs.8 blkid.8 logsave.8 fsck_ext2fs.8 e2freefrag.8
PORTDOCS=	COPYING RELEASE-NOTES

post-extract:
	@${CHMOD} u+w ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

PKGDEINSTALL=	${PKGINSTALL}

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: fails self-test
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
libintl=
.else
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
libintl=	"${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
.endif

post-patch::
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/lib/*/Makefile.in
# don't build/install libext2fs.info
	@${REINPLACE_CMD} -e 's/ install-doc-libs$$//' ${WRKSRC}/Makefile.in

.if ${MASTERDIR} == ${.CURDIR}
post-build:
# Relink e2fsck statically - We need to make sure that tools for the root file
# system are statically linked against anything that is outside the root fs,
# else we're in trouble if e2fsck is needed for boot:
# (we don't use e2fsck.static, since we can link libc.so dynamically)
	cd ${WRKSRC}/e2fsck && ${RM} -f e2fsck \
		&& ${GMAKE} e2fsck \
		STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a \
		../lib/libblkid.a  ../lib/libuuid.a" \
		LIBINTL=${libintl}
# Regression check: avoid a port (not upstream!) regression from 1.40.5,
# check that e2fsck isn't dynalinked against anything but libc.so:
	@${ECHO_CMD} -n "===>  checking that e2fsck depends on no shared objects beyond libc.so: "
	@a="$$(ldd ${WRKSRC}/e2fsck/e2fsck 2>/dev/null \
	    | ${GREP} -v 'not a dynamic executable' \
	    | ${GREP} '=>' \
	    | ${AWK}  '{print $$3;}' \
	    | ${GREP} -v '^/lib/libc\.so\.' || :)"; \
	if test "x$$a" = "x" ; then echo 'PASS' ; else \
	    echo 'FAIL' ; echo '===>  e2fsck depends on:' ; echo "$$a" ; exit 1 ; fi
# Update translation binary files
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/po && ${GMAKE} update-gmo
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
	cd ${WRKSRC}/tests && ${GMAKE} check \
	    || { head -n30000 ${WRKSRC}/tests/*.failed 2>/dev/null ; exit 1 ; }
# Now patch mke2fs.conf to default to 128 byte inodes - we need to do this
# after self tests since they assume 256 byte inodes.
	${PATCH} -N -d ${WRKSRC} <${FILESDIR}/diff-inode_size

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${PREFIX}/sbin/
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG} ; ${CAT} ${PKGMESSAGE} ; ${ECHO_MSG}
# the next line closes .if ${MASTERDIR} == ${.CURDIR}
.endif

.include <bsd.port.post.mk>
