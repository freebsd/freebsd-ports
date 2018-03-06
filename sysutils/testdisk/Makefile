# $FreeBSD$

PORTNAME=	testdisk
DISTVERSION=	7.1-WIP
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to check and undelete partitions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		jpeg localbase:ldflags ncurses tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-qt --without-ewf

PLIST_FILES=	bin/fidentify bin/photorec bin/testdisk \
		man/man8/fidentify.8.gz man/man8/photorec.8.gz \
		man/man8/testdisk.8.gz man/zh_CN/man8/fidentify.8.gz \
		man/zh_CN/man8/photorec.8.gz man/zh_CN/man8/testdisk.8.gz

PORTDOCS=	*

OPTIONS_DEFINE=	ICONV PROGSREISERFS NTFS DOCS
OPTIONS_DEFAULT=	ICONV

NTFS_DESC=		Support NTFS via fuse-ntfs extensions
PROGSREISERFS_DESC=	Use reiserfs extensions

ICONV_USES=		iconv
ICONV_CONFIGURE_OFF=	--without-iconv

NTFS_LIB_DEPENDS=	libntfs-3g.so:sysutils/fusefs-ntfs
NTFS_CONFIGURE_OFF=	--without-ntfs3g

PROGSREISERFS_LIB_DEPENDS=	libreiserfs.so:sysutils/progsreiserfs
PROGSREISERFS_CONFIGURE_OFF=	--without-reiserfs

.include <bsd.port.mk>
