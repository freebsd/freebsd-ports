# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.32
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities and library to manipulate an ext2 filesystem

USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-elf-shlibs
CONFIGURE_ENV=	CPPFLAGS="-Derrcode_t=long"

MAN1=	chattr.1 lsattr.1 uuidgen.1
MAN8=	badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 fsck.8 \
	findfs.8 mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8 \
	fsck.ext2.8 fsck.ext3.8 mkfs.ext2.8 mkfs.ext3.8

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LIST_HEAD|LIN_LST_HEAD|g ; \
		 s|et/com_err.h|com_err.h|g ; s|<malloc.h>|<stdlib.h>|'

pre-build:
	@cd ${WRKSRC}/lib/et && ${GMAKE}
	@cd ${WRKSRC}/lib/ss && ${GMAKE}

post-install:
	@${MKDIR} ${PREFIX}/include/ext2fs
	@${INSTALL_DATA} ${WRKSRC}/lib/ext2fs/*.h ${PREFIX}/include/ext2fs
	@${MKDIR} ${PREFIX}/include/uuid
	@${INSTALL_DATA} ${WRKSRC}/lib/uuid/*.h ${PREFIX}/include/uuid

.include <bsd.port.mk>
