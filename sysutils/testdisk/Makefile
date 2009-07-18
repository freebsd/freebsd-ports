# New ports collection makefile for:	testdisk
# Date created:				Feb 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	testdisk
PORTVERSION=	6.10
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Tool to check and undelete partitions

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--without-ewf

MAN1=		testdisk.1 photorec.1
PLIST_FILES=	sbin/testdisk sbin/photorec
PORTDOCS=	*

OPTIONS=	ICONV "Use iconv extensions" on \
		NTFSPROGS "Use ntfs extensions" off \
		PROGSREISERFS "Use reiserfs extensions" off
#		E2FSPROGS "Use ext2fs extensions" off \

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-doc-${PORTVERSION}${EXTRACT_SUFX}
.endif

.if !defined(WITHOUT_ICONV)
LIB_DEPENDS+=   iconv.3:${PORTSDIR}/converters/libiconv
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

.if defined(WITH_NTFSPROGS)
LIB_DEPENDS+=	ntfs.10:${PORTSDIR}/sysutils/ntfsprogs
.else
CONFIGURE_ARGS+=--without-ntfs
.endif

.if defined(WITH_PROGSREISERFS)
LIB_DEPENDS+=	reiserfs-0.3.0:${PORTSDIR}/sysutils/progsreiserfs
.else
CONFIGURE_ARGS+=--without-reiserfs
.endif

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e '/\/doc\/$$(PACKAGE)-$$(VERSION)/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
