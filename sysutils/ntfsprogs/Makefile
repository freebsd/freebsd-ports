# $FreeBSD$

PORTNAME=	ntfsprogs
PORTVERSION=	2.0.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-ntfs/NTFS%20Tools%20and%20Library/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate NTFS partitions

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Superseded by sysutils/fusefs-ntfs
EXPIRATION_DATE=	2016-12-31

CONFLICTS_INSTALL=	fusefs-ntfs-*

USES=		fuse pkgconfig libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	GNOMEVFS2 LOCK UBLIO UUID DOCS
OPTIONS_DEFAULT=LOCK UBLIO

GNOMEVFS2_DESC=	Install GnomeVFS 2.0 libntfs interface
LOCK_DESC=	Lock the device when mounting (avoids access)
UBLIO_DESC=	Enable user space cache for improved speed
UUID_DESC=	Generate DCE compliant UUIDs

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEVFS2}
WANT_GNOME=	yes
.endif

.if ${PORT_OPTIONS:MGNOMEVFS2}
CONFIGURE_ARGS+=--enable-gnome-vfs
USE_GNOME=	gnomevfs2
PLIST_SUB+=	GNOMEVFS2=""
.else
CONFIGURE_ARGS+=--disable-gnome-vfs
PLIST_SUB+=	GNOMEVFS2="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS:=	${CFLAGS:C/-O.?/-O0/g}
.endif

.if ${PORT_OPTIONS:MLOCK}
CFLAGS+=	-DUSE_LOCK
.endif

.if ${PORT_OPTIONS:MUUID}
LIB_DEPENDS+=	libuuid.so:misc/e2fsprogs-libuuid
CONFIGURE_ARGS+=--enable-uuid
.else
CONFIGURE_ARGS+=--disable-uuid
.endif

.if ${PORT_OPTIONS:MUBLIO}
LIB_DEPENDS+=	libublio.so:devel/libublio
CFLAGS+=	-DUSE_UBLIO
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: FreeBSD does not have cache support for block devices. This will considerably reduce the performance of this application, please consider enabling the UBLIO option and following the indications in the post-installation message." | ${FMT}
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MUBLIO}
post-patch:
	@${REINPLACE_CMD} -e 's|^libntfs_la_LIBADD =|& -lublio|' \
		${WRKSRC}/libntfs/Makefile.in
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
