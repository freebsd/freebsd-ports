# New ports collection makefile for:	fusefs-ntfs
# Date created: 			25 July 2006
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	ntfs
PORTVERSION=	1.913
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ntfs-3g.org/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Mount NTFS partitions (read/write) and disk images

BUILD_DEPENDS=	fusefs-libs>=2.6.0:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

OPTIONS=	LOCK "Lock the device when mounting (avoids access)" off \
		UBLIO "Enable user space cache for improved speed" on

MAN8=		ntfs-3g.8
MLINKS=		ntfs-3g.8 mount_ntfs-3g.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.if defined(WITH_LOCK)
CFLAGS+=	-DUSE_LOCK
.endif

.if defined(WITH_UBLIO)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ublio
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CFLAGS+=	-DUSE_UBLIO
SUB_FILES+=	pkg-message

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: FreeBSD does not have cache support for block devices. This will considerably reduce the performance of this application, please consider enabling the UBLIO option and following the indications in the post-installation message." | ${FMT}
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|,nonempty||' ${WRKSRC}/src/ntfs-3g.c

.include <bsd.port.post.mk>
