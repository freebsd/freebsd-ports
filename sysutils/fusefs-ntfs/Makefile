# New ports collection makefile for:	fusefs-ntfs
# Date created: 			25 July 2006
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	ntfs
PORTVERSION=	2011.4.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://tuxera.com/opensource/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g_ntfsprogs-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount NTFS partitions (read/write) and disk images

BUILD_DEPENDS=	fusefs-libs>=2.7.2:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

CONFLICTS_BUILD=	bonobo-1.*
CONFLICTS_INSTALL=	ntfsprogs-*
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_ICONV=	yes
USE_PKGCONFIG=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} --disable-mount-helper \
		--disable-mtab --with-fuse=external
CPPFLAGS+=	-I${WRKSRC}/include/ntfs-3g/ -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	LOCK "Lock the device when mounting (avoids access)" on \
		UBLIO "Enable user space cache for improved speed" on

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/ntfs-3g

MAN8=		mkntfs.8 ntfs-3g.8 ntfs-3g.probe.8 \
		ntfs-3g.secaudit.8 ntfs-3g.usermap.8 ntfscat.8 ntfsclone.8 \
		ntfscluster.8 ntfscmp.8 ntfscp.8 ntfsfix.8 ntfsinfo.8 \
		ntfslabel.8 ntfsls.8 ntfsprogs.8 ntfsresize.8 ntfsundelete.8

.include <bsd.port.pre.mk>

.if defined(WITH_LOCK)
CFLAGS+=	-DUSE_LOCK
.endif

.if defined(WITH_UBLIO)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ublio
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CFLAGS+=	-DUSE_UBLIO
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ENODATA|ENOATTR|' \
		${WRKSRC}/libntfs-3g/object_id.c \
		${WRKSRC}/libntfs-3g/reparse.c \
		${WRKSRC}/libntfs-3g/security.c
	@${REINPLACE_CMD} -e 's|\($$(AM_CFLAGS)\) \(-I$$(top_srcdir)/include/ntfs-3g\)|\2 \1|' \
		${WRKSRC}/libntfs-3g/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's|^(install-data-am:) .*|\1|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
