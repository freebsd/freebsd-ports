# New ports collection makefile for:	testdisk
# Date created:				Feb 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	testdisk
PORTVERSION=	5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	flz@xbsd.org
COMMENT=	Tool to check and undelete partitions

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
MAN1=		testdisk.1

CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"

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
	${REINPLACE_CMD} -e 's|^transform.*||' ${WRKSRC}/Makefile.in \
					       ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's|/doc/.(PACKAGE)-.(VERSION)|/doc/${PORTNAME}|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
