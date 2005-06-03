# New ports collection makefile for:	ntfsprogs
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ntfsprogs
PORTVERSION=	1.9.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-ntfs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate NTFS partitions

GNU_CONFIGURE=	yes
USE_GCC=	3.4
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	GNOMEVFS2 "Install Gnome-VFS-2.0 libntfs interface" off

MAN8=		libntfs-gnomevfs.8 \
		mkntfs.8	\
		ntfscat.8	\
		ntfsclone.8	\
		ntfscluster.8	\
		ntfsfix.8	\
		ntfsinfo.8	\
		ntfslabel.8	\
		ntfsls.8	\
		ntfsprogs.8	\
		ntfsresize.8	\
		ntfsundelete.8

.include <bsd.port.pre.mk>

.if defined(WITH_GNOMEVFS2)
USE_GNOME=	gnomevfs2
PLIST_SUB=	GNOMEVFS2=""
.else
CONFIGURE_ARGS=	--disable-gnome-vfs
PLIST_SUB=	GNOMEVFS2="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^transform.*||'	${WRKSRC}/Makefile.in		\
						${WRKSRC}/libntfs/Makefile.in	\
						${WRKSRC}/ntfsprogs/Makefile.in

.include <bsd.port.post.mk>
