# $FreeBSD$

PORTNAME=	openzfs
PORTVERSION=	2019101600
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-kmod

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	OpenZFS kernel module for FreeBSD

LICENSE=	CDDL

USES=		kmod
USE_GITHUB=	yes
GH_ACCOUNT=	zfsonfreebsd
GH_PROJECT=	ZoF
GH_TAGNAME=	d4169da
KMODTARGET?=	openzfs.ko

PLIST_FILES=	${KMODDIR}/${KMODTARGET}

OPTIONS_DEFINE=	DEBUG GCOV
OPTIONS_SUB=	yes
GCOV_DESC=	Build kernel module with GCOV support (Requires gcc)

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1200504) || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300013)
IGNORE=      needs FreeBSD 12/13 with AES-CCM support
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_OPTS+=	WITH_DEBUG=true
PLIST_FILES+=	${KMODDIR}/${KMODTARGET}.debug
.endif

.if ${PORT_OPTIONS:MGCOV}
USE_GCC=yes
MAKE_OPTS+=	WITH_GCOV=true
.endif

post-patch:
	${CP} ${FILESDIR}/zfs_gitrev.h ${WRKSRC}/include

do-build:
	(cd ${WRKSRC}/module/ && make -f Makefile.bsd CC=${CC} ${MAKE_OPTS})

do-install:
	${INSTALL} ${WRKSRC}/module/openzfs.ko ${STAGEDIR}${KMODDIR}/${KMODTARGET}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL} ${WRKSRC}/module/openzfs.ko.debug ${STAGEDIR}${KMODDIR}/${KMODTARGET}.debug
.endif

.include <bsd.port.post.mk>
