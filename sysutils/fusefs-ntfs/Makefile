# Created by: Max Khon
# $FreeBSD$

PORTNAME=	ntfs
PORTVERSION=	2012.1.15
CATEGORIES=	sysutils
MASTER_SITES=	http://tuxera.com/opensource/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g_ntfsprogs-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount NTFS partitions (read/write) and disk images

LICENSE=	GPLv2

CONFLICTS_BUILD=	bonobo-1.*
CONFLICTS_INSTALL=	ntfsprogs-*
USES=		fuse pkgconfig iconv
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} --disable-mount-helper \
		--disable-mtab --with-fuse=external
CPPFLAGS+=	-I${WRKSRC}/include/ntfs-3g/ -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	LOCK UBLIO
OPTIONS_DEFAULT=LOCK UBLIO
LOCK_DESC=	Lock the device when mounting (avoids access)
UBLIO_DESC=	Enable user space cache for improved speed

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/ntfs-3g

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLOCK}
CFLAGS+=	-DUSE_LOCK
.endif

.if ${PORT_OPTIONS:MUBLIO}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ublio
LIB_DEPENDS+=	ublio:${PORTSDIR}/devel/libublio
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
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
