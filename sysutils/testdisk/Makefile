# $FreeBSD$

PORTNAME=	testdisk
PORTVERSION=	6.13
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Tool to check and undelete partitions

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
CONFIGURE_ARGS=	--without-ewf

MAN8=		fidentify.8 testdisk.8 photorec.8
PLIST_FILES=	bin/fidentify bin/testdisk bin/photorec
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

.include <bsd.port.pre.mk>

#.if !defined(NOPORTDOCS)
#DISTFILES+=	${PORTNAME}-doc-${PORTVERSION}${EXTRACT_SUFX}
#.endif

.if ${PORT_OPTIONS:MICONV}
USES=		iconv
.else
CONFIGURE_ARGS+=--without-iconv
.endif

# e2fsprogs does not provide ext2fs.so any more
# since it does not do 'make install-libs'
#.if defined(WITH_E2FSPROGS)
#LIB_DEPENDS+=	ext2fs.2:${PORTSDIR}/sysutils/e2fsprogs
#.else
#CONFIGURE_ARGS+=--without-ext2fs
#.endif

.if ${PORT_OPTIONS:MNTFS3G}
LIB_DEPENDS+=	ntfs-3g:${PORTSDIR}/sysutils/fusefs-ntfs
.else
CONFIGURE_ARGS+=--without-ntfs3g
.endif

.if ${PORT_OPTIONS:MNTFSPROGS}
LIB_DEPENDS+=	ntfs:${PORTSDIR}/sysutils/ntfsprogs
.else
CONFIGURE_ARGS+=--without-ntfs
.endif

.if ${PORT_OPTIONS:MPROGSREISERFS}
LIB_DEPENDS+=	reiserfs-0.3.0:${PORTSDIR}/sysutils/progsreiserfs
.else
CONFIGURE_ARGS+=--without-reiserfs
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/doc\/testdisk\/html/d' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e '/\/doc\/$$(PACKAGE)-$$(VERSION)/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
