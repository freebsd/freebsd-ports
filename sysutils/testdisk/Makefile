# New ports collection makefile for:	testdisk
# Date created:				Feb 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	testdisk
PORTVERSION=	5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	flz@xbsd.org
COMMENT=	Tool to check and undelete partitions

WRKSRC=		${WRKDIR}/${PORTNAME}/src
USE_REINPLACE=	yes
PLIST_FILES=	bin/testdisk

.if defined(WITH_E2FSPROGS)
BUILD_DEPENDS+=	ext2fs.2:${PORTSDIR}/sysutils/e2fsprogs
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500040
IGNORE=		"Requires FreeBSD 5.x, some defines are missing in sys/disk.h before __FreeBSD_version 500040"
.endif

.if !defined(WITH_E2FSPROGS)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can define the following for additional features:"
	@${ECHO_MSG} ""
.if !defined(WITH_E2FSPROGS)
	@${ECHO_MSG} "WITH_E2FSPROGS  - Use ext2fs extensions.
.endif
	@${ECHO_MSG} ""
.endif

post-patch:
.if defined(WITH_E2FSPROGS)
	@${REINPLACE_CMD} -e 's|-DHAVE_PROGSREISERFS31.*||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^\(LIBS=\).*|\1${PREFIX}/lib/libext2fs.a|' ${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e 's|-DHAVE_E2FSPROGS.*||' ${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -e 's|^bsd:|all:|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^\(LIBSA=\).*|\1|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/testdisk ${PREFIX}/bin

.include <bsd.port.post.mk>
