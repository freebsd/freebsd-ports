# New ports collection makefile for:	testdisk
# Date created:				Feb 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	testdisk
PORTVERSION=	5.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Tool to check and undelete partitions

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

MAN1=		testdisk.1 photorec.1
PLIST_FILES=	sbin/testdisk sbin/photorec
PORTDOCS=	*

OPTIONS=	E2FSPROGS "Use ext2fs extensions" off \
		NTFSPROGS "Use ntfs extensions" off \
		PROGSREISERFS "Use reiserfs extensions" off

.include <bsd.port.pre.mk>

.if defined(WITH_E2FSPROGS)
LIB_DEPENDS+=	ext2fs.2:${PORTSDIR}/sysutils/e2fsprogs
.endif

.if defined(WITH_NTFSPROGS)
LIB_DEPENDS+=	ntfs.6:${PORTSDIR}/sysutils/ntfsprogs
.endif

.if defined(WITH_PROGSREISERFS)
LIB_DEPENDS+=	reiserfs-0.3.0:${PORTSDIR}/sysutils/progsreiserfs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)/doc|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
