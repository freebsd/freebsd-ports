# New ports collection makefile for:	ntfsprogs
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ntfsprogs
PORTVERSION=	1.9.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-ntfs

MAINTAINER=	flz@xbsd.org
COMMENT=	Utilities and library to manipulate NTFS partitions

GNU_CONFIGURE=	yes
USE_GCC=	3.3
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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

.if defined(WITH_GNOMEVFS2)
USE_GNOME=	gnomevfs2
PLIST_SUB=	GNOMEVFS2=""
MAN8+=		libntfs-gnomevfs.8
.else
CONFIGURE_ARGS=	--disable-gnome-vfs
PLIST_SUB=	GNOMEVFS2="@comment "
.endif

.if !defined(WITH_GNOMEVFS2)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can define the following for additional features:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_GNOMEVFS2  - Installs Gnome-VFS-2.0 libntfs interface.
	@${ECHO_MSG} ""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^transform.*||'	${WRKSRC}/Makefile.in		\
						${WRKSRC}/libntfs/Makefile.in	\
						${WRKSRC}/ntfsprogs/Makefile.in
	${REINPLACE_CMD} -e 's| bswap_| bswap|' ${WRKSRC}/include/ntfs/endians.h

.include <bsd.port.mk>
