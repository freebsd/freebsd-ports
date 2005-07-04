# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.38
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Utilities and library to manipulate ext2/ext3 filesystems

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

PATCH_STRIP=	-p1
USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install install-libs
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-elf-shlibs --disable-fsck "--with-ldopts=-L${LOCALBASE}/lib"
CONFIGURE_ENV+=	CPPFLAGS='-I${WRKSRC}/lib -I${LOCALBASE}/include'
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
MAKE_ARGS+=	STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a ../lib/libblkid.a  ../lib/libuuid.a ${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
PLIST_SUB=	NLS=""
.endif

CONFLICTS=	ossp-uuid-[0-9]*

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=	chattr.1 lsattr.1 uuidgen.1 compile_et.1 mk_cmds.1
MAN3=	uuid.3 uuid_clear.3 com_err.3 uuid_compare.3 uuid_copy.3 \
	uuid_generate.3 uuid_is_null.3 uuid_parse.3 uuid_time.3 \
	uuid_unparse.3 uuid_generate_random.3 uuid_generate_time.3 \
	libblkid.3
MAN8=	badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 \
	mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8 \
	fsck.ext2.8 fsck.ext3.8 mkfs.ext2.8 mkfs.ext3.8 \
	findfs.8 blkid.8 logsave.8

pre-everything::
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

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E -e 's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/lib/*/Makefile.in

pre-install:
	${RM} -f ${PKGMESSAGE}
	${SED} -e "s:%%PREFIX%%:${PREFIX}:" ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-build:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/po && ${GMAKE} update-gmo
.endif
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} -o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c
	cd ${WRKSRC}/tests && ${GMAKE} check

post-install:
	${RM} ${PREFIX}/sbin/filefrag
	${RM} ${PREFIX}/man/man8/filefrag.8
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${PREFIX}/sbin/
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
