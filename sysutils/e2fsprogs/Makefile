# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.35.w20040131
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.35-WIP-0131

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Utilities and library to manipulate an ext2 or ext3 filesystem

.if !defined(DISABLE_NLS)
USE_GETTEXT=	yes
.endif

WRKSRC=	${WRKDIR}/${PORTNAME}-1.35

USE_GCC=	3.3
PATCH_STRIP=	-p1
USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-elf-shlibs --disable-fsck "--with-ldopts=-L${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
.if defined(DISABLE_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
MAKE_ARGS+=	STATIC_LIBS="../lib/libext2fs.a ../lib/libcom_err.a ../lib/libblkid.a  ../lib/libuuid.a ${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a"
PLIST_SUB=	NLS=""
.endif

CONFLICTS=	ossp-uuid-*

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=	chattr.1 lsattr.1 uuidgen.1
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
	${CHMOD} u+w ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot

post-patch:
	${REINPLACE_CMD} -e 's|-DRESOURCE_TRACK||' ${WRKSRC}/e2fsck/Makefile.in
	${GUNZIP_CMD} ${WRKSRC}/tests/m_*/expect*.gz
	${REINPLACE_CMD} -e 's|OS type: Linux|OS type: (unknown os)|' \
	-e 's|Filesystem OS type:       Linux|Filesystem OS type:       unknown|' \
	-e 's|group root|group wheel|' \
	-e '/Exit status is 0/ N;s/Exit status is 0\n/Exit status is 0/' \
	${WRKSRC}/tests/m_*/expect.1

post-configure:
	@${CAT} ${FILESDIR}/pkg-message.in | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" > ${PKGMESSAGE}

post-build:
	cd ${WRKSRC}/tests && ${GMAKE} check
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} -o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c

post-install:
	${RM} ${PREFIX}/sbin/filefrag
	${RM} ${PREFIX}/man/man8/filefrag.8
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/e2fsck/e2fsck.shared ${PREFIX}/sbin/e2fsck
	${INSTALL_PROGRAM} ${WRKSRC}/e2fsck/e2fsck.static ${PREFIX}/sbin/e2fsck.static
	${MKDIR} ${PREFIX}/include/ext2fs
	${INSTALL_DATA} ${WRKSRC}/lib/ext2fs/*.h ${PREFIX}/include/ext2fs/
	${MKDIR} ${PREFIX}/include/uuid
	${INSTALL_DATA} ${WRKSRC}/lib/uuid/*.h ${PREFIX}/include/uuid/
.for i in e2p ext2fs uuid
	${INSTALL_DATA} ${WRKSRC}/lib/${i}/lib${i}.a ${PREFIX}/lib/
.endfor
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
