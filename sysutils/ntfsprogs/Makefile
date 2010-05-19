# New ports collection makefile for:	ntfsprogs
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ntfsprogs
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-ntfs/NTFS%20Tools%20and%20Library/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate NTFS partitions

BUILD_DEPENDS=	fusefs-libs>2.5:${PORTSDIR}/sysutils/fusefs-libs

USE_GNOME=	pkgconfig
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	GNOMEVFS2 "Install GnomeVFS 2.0 libntfs interface" off \
		LOCK "Lock the device when mounting (avoids access)" on \
		UBLIO "Enable user space cache for improved speed" on \
		UUID "Generate DCE compliant UUIDs" off

MAN8=	libntfs.8 libntfs-gnomevfs.8 mkntfs.8 \
	ntfscat.8 ntfsclone.8 ntfscluster.8 ntfscmp.8 \
	ntfscp.8 ntfsfix.8 ntfsinfo.8 ntfslabel.8 ntfsls.8 ntfsmount.8 \
	ntfsprogs.8 ntfsresize.8 ntfsundelete.8
MLINKS=	ntfsmount.8 mount_ntfs-fuse.8

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS:=	${CFLAGS:C/-O.?/-O0/g}
.endif

.if defined(WITH_GNOMEVFS2)
CONFIGURE_ARGS+=--enable-gnome-vfs
USE_GNOME=	gnomevfs2
PLIST_SUB+=	GNOMEVFS2=""
.else
CONFIGURE_ARGS+=--disable-gnome-vfs
PLIST_SUB+=	GNOMEVFS2="@comment "
.endif

.if defined(WITH_LOCK)
CFLAGS+=	-DUSE_LOCK
.endif

.if defined(WITH_UUID)
LIB_DEPENDS+=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid
CONFIGURE_ARGS+=--enable-uuid
.else
CONFIGURE_ARGS+=--disable-uuid
.endif

.if defined(WITH_UBLIO)
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CFLAGS+=	-DUSE_UBLIO
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: FreeBSD does not have cache support for block devices. This will considerably reduce the performance of this application, please consider enabling the UBLIO option and following the indications in the post-installation message." | ${FMT}
	@${ECHO_MSG}
.endif

.if defined(WITH_UBLIO)
post-patch:
	@${REINPLACE_CMD} -e 's|^libntfs_la_LIBADD =|& -lublio|' \
		${WRKSRC}/libntfs/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
