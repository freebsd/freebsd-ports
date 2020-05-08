# $FreeBSD$

PORTNAME=	openzfs
PORTVERSION=	2020050800
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-kmod

MAINTAINER=	freqlabs@FreeBSD.org
COMMENT=	OpenZFS kernel module for FreeBSD

LICENSE=	CDDL

USES=		kmod
USE_GITHUB=	yes
GH_ACCOUNT=	openzfs
GH_PROJECT=	zfs
GH_TAGNAME=	1cc635a2d
KMODTARGET?=	openzfs.ko

PLIST_FILES=	${KMODDIR}/${KMODTARGET}

OPTIONS_DEFINE=	DEBUG GCOV
OPTIONS_SUB=	yes
GCOV_DESC=	Build kernel module with GCOV support (Requires gcc)

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1200504) || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300013)
IGNORE=	needs FreeBSD 12/13 with AES-CCM support
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_OPTS+=	WITH_DEBUG=true
PLIST_FILES+=	${KMODDIR}/${KMODTARGET}.debug
.endif

.if ${PORT_OPTIONS:MGCOV}
USE_GCC=	yes
MAKE_OPTS+=	WITH_GCOV=true
.endif

ZFS_META_GITREV=	${GH_PROJECT}-${GH_TAGNAME}
ZFS_META_RELEASE=	${GH_PROJECT}_${GH_TAGNAME}
ZFS_META_VERSION=	${DISTVERSIONPREFIX}${PORTVERSION}

post-patch:
	${ECHO} '#define ZFS_META_GITREV "${ZFS_META_GITREV}"' > ${WRKSRC}/include/zfs_gitrev.h
	${ECHO} '#define ZFS_META_RELEASE "${ZFS_META_RELEASE}"' > ${WRKSRC}/zfs_config.h
	${ECHO} '#define ZFS_META_VERSION "${ZFS_META_VERSION}"' >> ${WRKSRC}/zfs_config.h

do-build:
	(cd ${WRKSRC}/module/ && make -f Makefile.bsd CC=${CC} ${MAKE_OPTS})

do-install:
	${INSTALL} ${WRKSRC}/module/openzfs.ko ${STAGEDIR}${KMODDIR}/${KMODTARGET}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL} ${WRKSRC}/module/openzfs.ko.debug ${STAGEDIR}${KMODDIR}/${KMODTARGET}.debug
.endif

.include <bsd.port.post.mk>
