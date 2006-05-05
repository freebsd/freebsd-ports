# New ports collection makefile for:	ntfsprogs
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ntfsprogs
PORTVERSION=	1.13.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-ntfs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate NTFS partitions

GNU_CONFIGURE=	yes
USE_GCC=	3.4+
USE_GETOPT_LONG=yes
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	PKG_CONFIG=${LOCALBASE}/bin/pkg-config
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	GNOMEVFS2 "Install GnomeVFS 2.0 libntfs interface" off \
		FUSE "Compile with Fuse interface" off

MAN8=		libntfs-gnomevfs.8 \
		mkntfs.8	\
		ntfscat.8	\
		ntfsclone.8	\
		ntfscluster.8	\
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

.if defined(WITH_GNOMEVFS2)
CONFIGURE_ARGS+=--enable-gnome-vfs
USE_GNOME=	gnomevfs2
PLIST_SUB+=	GNOMEVFS2=""
.else
CONFIGURE_ARGS+=--disable-gnome-vfs
PLIST_SUB+=	GNOMEVFS2="@comment "
.endif

.if defined(WITH_FUSE)
CONFIGURE_ARGS+=--enable-fuse-module
PLIST_SUB+=	FUSE=""
USE_GNOME+=	pkgconfig
BUILD_DEPENDS+=	fusefs-libs>2.5:${PORTSDIR}/sysutils/fusefs-libs
MLINKS+=	ntfsmount.8 mount.ntfs-fuse.8
.else
CONFIGURE_ARGS+=--disable-fuse-module
PLIST_SUB+=	FUSE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/sbin/|${PREFIX}/sbin/|' ${WRKSRC}/ntfsprogs/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/\(gnome-vfs-2.0/modules\)|${X11BASE}/lib/\1|; \
		 s|$$(sysconfdir)/\(gnome-vfs-2.0/modules\)|${X11BASE}/etc/\1|' \
		${WRKSRC}/libntfs/Makefile.in

.include <bsd.port.post.mk>
