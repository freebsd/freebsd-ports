# New ports collection makefile for:	e2fsprogs
# Date created:				3 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.22
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-elf-shlibs
CONFIGURE_ENV=	CPPFLAGS="-I/usr/include -I${LOCALBASE}/include \
			  -Derrcode_t=long" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	chattr.1 lsattr.1 uuidgen.1
MAN8=	badblocks.8 debugfs.8 dumpe2fs.8 e2fsck.8 e2image.8 e2label.8 fsck.8 \
	mke2fs.8 mklost+found.8 resize2fs.8 tune2fs.8

post-patch:
	@find ${WRKSRC} -name "*.[ch]" | xargs ${PERL} -pi -e \
		's|LIST_HEAD|LIN_LST_HEAD|g ; \
		 s|et/com_err.h|com_err.h|g ; s|<malloc.h>|<stdlib.h>|'

post-install:
	${MKDIR} ${PREFIX}/include/ext2fs
	${INSTALL_DATA} ${WRKSRC}/lib/ext2fs/*.h ${PREFIX}/include/ext2fs

.include <bsd.port.mk>
