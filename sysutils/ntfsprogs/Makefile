# New ports collection makefile for:	ntfsprogs
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ntfsprogs
PORTVERSION=	1.13.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-ntfs

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Utilities and library to manipulate NTFS partitions

WANT_GNOME=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	PKG_CONFIG=${LOCALBASE}/bin/pkg-config \
		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

OPTIONS=	FUSE "Compile with Fuse interface" off \
		GNOMEVFS2 "Install GnomeVFS 2.0 libntfs interface" off \
		LOCK "Lock the device when mounting (avoids access)" off \
		UBLIO "Enable user space cache for improved speed" on

MAN8=		libntfs-gnomevfs.8 \
		mkntfs.8	\
		ntfscat.8	\
		ntfsclone.8	\
		ntfscluster.8	\
		ntfscmp.8	\
		ntfscp.8	\
		ntfsfix.8	\
		ntfsinfo.8	\
		ntfslabel.8	\
		ntfsls.8	\
		ntfsmount.8	\
		ntfsprogs.8	\
		ntfsresize.8	\
		ntfsundelete.8

MLINKS=		mkntfs.8 mkfs.ntfs.8

.include <bsd.port.pre.mk>

.if defined(WITH_FUSE) || defined(WITH_UBLIO)
SUB_FILES+=	pkg-message

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.endif

.if defined(WITH_FUSE)
CONFIGURE_ARGS+=--enable-fuse-module
PLIST_SUB+=	FUSE=""
USE_GNOME+=	pkgconfig
BUILD_DEPENDS+=	fusefs-libs>2.5:${PORTSDIR}/sysutils/fusefs-libs
MLINKS+=	ntfsmount.8 mount_ntfs-fuse.8
.else
CONFIGURE_ARGS+=--disable-fuse-module
PLIST_SUB+=	FUSE="@comment "
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

.if defined(WITH_UBLIO)
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CFLAGS+=	-DUSE_UBLIO
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: FreeBSD does not have cache support for block devices. This will considerably reduce the performance of this application, please consider enabling the UBLIO option and following the indications in the post-installation message." | ${FMT}
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)/sbin|$$(DESTDIR)/${PREFIX}/sbin|' \
		${WRKSRC}/ntfsprogs/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/\(gnome-vfs-2.0/modules\)|${LOCALBASE}/lib/\1|; \
		 s|$$(sysconfdir)/\(gnome-vfs-2.0/modules\)|${LOCALBASE}/etc/\1|' \
		${WRKSRC}/libntfs/Makefile.in
.if defined(WITH_UBLIO)
	@${REINPLACE_CMD} -e 's|^libntfs_la_LIBADD =|& -lublio|' \
		${WRKSRC}/libntfs/Makefile.in
.endif

.include <bsd.port.post.mk>
