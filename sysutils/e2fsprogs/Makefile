# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.35
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Utilities and library to manipulate an ext2 or ext3 filesystem

.if !defined(DISABLE_NLS)
USE_GETTEXT=	yes
.endif

USE_GCC=	3.3
PATCH_STRIP=	-p1
USE_AUTOCONF=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install install-libs
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-elf-shlibs --disable-fsck "--with-ldopts=-L${LOCALBASE}/lib"
CONFIGURE_ENV+=	CPPFLAGS='-I${WRKSRC}/lib -I${LOCALBASE}/include'
.if defined(DISABLE_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
MAKE_ARGS+=	STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a ../lib/libblkid.a  ../lib/libuuid.a ${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
PLIST_SUB=	NLS=""
.endif

CONFLICTS=	ossp-uuid-*

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=	chattr.1 lsattr.1 uuidgen.1 compile_et.1 mk_cmds.1
MAN3=	libuuid.3 uuid_clear.3 com_err.3 uuid_compare.3 uuid_copy.3 \
	uuid_generate.3 uuid_is_null.3 uuid_parse.3 uuid_time.3 \
	uuid_unparse.3 uuid_generate_random.3 uuid_generate_time.3 \
	libblkid.3
MAN8=	badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 \
	mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8 \
	fsck.ext2.8 fsck.ext3.8 mkfs.ext2.8 mkfs.ext3.8 \
	findfs.8 blkid.8 logsave.8

pre-everything::
	@${ECHO_CMD} "-------------------------------------------------------------"
.if defined(DISABLE_NLS)
	@${ECHO_CMD} "National language support disabled, -DDISABLE_NLS in effect. "
.else
	@${ECHO_CMD} "Use -DDISABLE_NLS to build without national language support."
.endif
	@${ECHO_CMD} "-------------------------------------------------------------"

post-extract:
	${CHMOD} u+w ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	${REINPLACE_CMD} -e 's|-DRESOURCE_TRACK||' ${WRKSRC}/e2fsck/Makefile.in
	${GUNZIP_CMD} ${WRKSRC}/tests/m_*/expect*.gz
	${REINPLACE_CMD} -e 's|OS type: Linux|OS type: (unknown os)|' \
	-e 's|Filesystem OS type:       Linux|Filesystem OS type:       unknown|' \
	-e 's|group root|group wheel|' \
	-e '/Exit status is 0/ N;s/Exit status is 0\n/Exit status is 0/' \
	${WRKSRC}/tests/m_*/expect.1
.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64"
	${RM} -rf ${WRKSRC}/tests/m_large_file
.endif

pre-install:
	${RM} -f ${PKGMESSAGE}
	${SED} -e "s:%%PREFIX%%:${PREFIX}:" ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-build:
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} -o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c
	cd ${WRKSRC}/tests && ${GMAKE} check

post-install:
	${RM} ${PREFIX}/sbin/filefrag
	${RM} ${PREFIX}/man/man8/filefrag.8
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/e2fsck/e2fsck.shared ${PREFIX}/sbin/e2fsck
	${INSTALL_PROGRAM} ${WRKSRC}/e2fsck/e2fsck.static ${PREFIX}/sbin/e2fsck.static
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
