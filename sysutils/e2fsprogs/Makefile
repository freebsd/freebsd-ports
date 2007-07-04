# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.40
PORTREVISION?=	0
CATEGORIES?=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	matthias.andree@gmx.de
COMMENT?=	Utilities and library to manipulate ext2/ext3 filesystems

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=	--disable-fsck --disable-e2initrd-helper \
			'--with-ldopts=-L${LOCALBASE}/lib' \
			--with-cc='${CC}' --with-linker='${LD}' \
			--with-ccopts='${CFLAGS}' \
			--with-root-prefix='${PREFIX}'\
			 --infodir=${PREFIX}/info \
			 --mandir=${MANPREFIX}/man
# for unknown reasons, the assembly bitops cause SIGSEGV.
# _EXT2_USE_C_VERSIONS_ uses C bitops, these appear to work fine.
CONFIGURE_ENV+=	CPPFLAGS='${CPPFLAGS} -I${WRKSRC}/lib -I${LOCALBASE}/include -D_EXT2_USE_C_VERSIONS_'
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
MAKE_ARGS+=	STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a ../lib/libblkid.a  \
		../lib/libuuid.a ${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
PLIST_SUB=	NLS=""
.endif
USE_LDCONFIG=	yes
PKGDEINSTALL=	${PKGINSTALL}

.if !defined(MASTERDIR)
MAN1=	chattr.1 lsattr.1
MAN5=	e2fsck.conf.5 mke2fs.conf.5
MAN8=	badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 \
	mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8 \
	fsck.ext2.8 fsck.ext3.8 mkfs.ext2.8 mkfs.ext3.8 \
	findfs.8 blkid.8 logsave.8 fsck_ext2fs.8

pre-build:
	@${ECHO_CMD} "-------------------------------------------------------------"
.if defined(WITHOUT_NLS)
	@${ECHO_CMD} "National language support disabled, -DWITHOUT_NLS in effect. "
.else
	@${ECHO_CMD} "Use -DWITHOUT_NLS to build without national language support."
.endif
	@${ECHO_CMD} "-------------------------------------------------------------"

post-extract:
	${CHMOD} u+w ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E -e 's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/lib/*/Makefile.in
	@: # disable uuidgen
	${REINPLACE_CMD} \
		-e 's/^\(UPROGS.*\) uuidgen\(.*\)/\1\2/' \
		-e 's/^\(UMANPAGES.*\) uuidgen.1\(.*\)/\1\2/' \
		${WRKSRC}/misc/Makefile.in

.if ${MASTERDIR} == ${.CURDIR}
post-build:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/po && ${MAKE} update-gmo
.endif
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -s -static ${LIBS} -o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c
	cd ${WRKSRC}/tests && ${MAKE} check
# While the ${MAKE} check can take a minute on an end user's system, the
# correctness of tools such as e2fsck is critical to the health of the
# file systems.  The upstream is not using any *BSD as his development
# system, and therefore let's exercise due diligence in running the self-
# test on each and every system and not just package building hosts.
# There have been subtle failures induced by Linux-isms in the past,
# and every release I've packaged introduced some minor regressions.
# -- Matthias Andree, package maintainer, 2006-06-12

post-install:
	${RM} ${PREFIX}/sbin/filefrag
	${RM} ${PREFIX}/man/man8/filefrag.8
	${RM} ${PREFIX}/info/libext2fs.info.gz
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${PREFIX}/sbin/
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${PREFIX}/man/man8/
	[ -f ${PREFIX}/etc/mke2fs.conf ] || \
		${CP} -p ${PREFIX}/etc/mke2fs.conf.dist ${PREFIX}/etc/mke2fs.conf
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
