# New ports collection makefile for:	testdisk
# Date created:				Feb 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	testdisk
PORTVERSION=	5.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	flz@xbsd.org
COMMENT=	Tool to check and undelete partitions

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

MAN1=		testdisk.1
PLIST_FILES=	sbin/testdisk
PORTDOCS=	*

.if defined(WITH_E2FSPROGS)
LIB_DEPENDS+=	ext2fs.2:${PORTSDIR}/sysutils/e2fsprogs
.endif

.if defined(WITH_NTFSPROGS)
LIB_DEPENDS+=	ntfs.5:${PORTSDIR}/sysutils/ntfsprogs
.endif

.if defined(WITH_PROGSREISERFS)
LIB_DEPENDS+=	reiserfs-0.3.0:${PORTSDIR}/sysutils/progsreiserfs
.endif

.if !defined(WITH_E2FSPROGS) || !defined(WITH_NTFSPROGS) || !defined(WITH_PROGSREISERFS)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can define the following for additional features:"
	@${ECHO_MSG} ""
.if !defined(WITH_E2FSPROGS)
	@${ECHO_MSG} "WITH_E2FSPROGS		- Use ext2fs extensions.
.endif
.if !defined(WITH_NTFSPROGS)
	@${ECHO_MSG} "WITH_NTFSPROGS		- Use ntfs extensions.
.endif
.if !defined(WITH_PROGSREISERFS)
	@${ECHO_MSG} "WITH_PROGSREISERFS	- Use reiserfs extensions.
.endif
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)/doc|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
