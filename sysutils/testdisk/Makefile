PORTNAME=	testdisk
DISTVERSION=	7.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Tool to check and undelete partitions
WWW=		https://www.cgsecurity.org/wiki/TestDisk

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		jpeg localbase:ldflags ncurses tar:bzip2

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--disable-qt \
				--without-ewf

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS ICONV NTFS PROGSREISERFS
OPTIONS_DEFAULT=	ICONV

NTFS_DESC=		Support NTFS via fuse-ntfs extensions
PROGSREISERFS_DESC=	Use reiserfs extensions

ICONV_USES=		iconv
ICONV_CONFIGURE_OFF=	--without-iconv

NTFS_LIB_DEPENDS=	libntfs-3g.so:sysutils/fusefs-ntfs
NTFS_CONFIGURE_OFF=	--without-ntfs3g

PROGSREISERFS_LIB_DEPENDS=	libreiserfs-0.3.so.0:sysutils/progsreiserfs
PROGSREISERFS_CONFIGURE_OFF=	--without-reiserfs

.include <bsd.port.mk>
