# $FreeBSD$

PORTNAME=	testdisk
PORTVERSION=	7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Tool to check and undelete partitions

USES=		jpeg ncurses tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
CONFIGURE_ARGS=	--disable-qt --without-ewf

PLIST_FILES=	bin/fidentify bin/photorec bin/testdisk \
		man/man8/fidentify.8.gz man/man8/photorec.8.gz \
		man/man8/qphotorec.8.gz man/man8/testdisk.8.gz \
		man/zh_CN/man8/fidentify.8.gz man/zh_CN/man8/photorec.8.gz \
		man/zh_CN/man8/qphotorec.8.gz man/zh_CN/man8/testdisk.8.gz \
		share/icons/hicolor/48x48/apps/qphotorec.png \
		share/icons/hicolor/scalable/apps/qphotorec.svg

PORTDOCS=	*

OPTIONS_DEFINE=	ICONV PROGSREISERFS NTFS DOCS
OPTIONS_DEFAULT=	ICONV
OPTIONS_SINGLE=	NTFS
OPTIONS_SINGLE_NTFS=	NTFS3G NTFSPROGS
NTFS_DESC=		Support NTFS
NTFS3G_DESC=		Use fusefs-ntfs extensions
NTFSPROGS_DESC=		Use ntfsprogs extensions
PROGSREISERFS_DESC=	Use reiserfs extensions
#		E2FSPROGS "Use ext2fs extensions" off \

ICONV_USES=		iconv
ICONV_CONFIGURE_OFF=	--without-iconv

# e2fsprogs does not provide ext2fs.so any more
# since it does not do 'make install-libs'
#.if defined(WITH_E2FSPROGS)
#LIB_DEPENDS+=	ext2fs.2:sysutils/e2fsprogs
#.else
#CONFIGURE_ARGS+=--without-ext2fs
#.endif

NTFS3G_LIB_DEPENDS=	libntfs-3g.so:sysutils/fusefs-ntfs
NTFS3G_CONFIGURE_OFF=	--without-ntfs3g

NTFSPROGS_LIB_DEPENDS=	libntfs.so:sysutils/ntfsprogs
NTFS_PROGS_CONFIGURE_ARGS=	--without-ntfs

PROGSREISERFS_LIB_DEPENDS=	libreiserfs-0.3.so:sysutils/progsreiserfs
PROGSREISERFS_CONFIGURE_OFF=	--without-reiserfs

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/doc\/testdisk\/html/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
