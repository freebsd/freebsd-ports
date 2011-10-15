# New ports collection makefile for:    openafs
# Date created:                         2010-11-06
# Whom:                                 Ben Kaduk <kaduk@mit.edu>
# Based on:                             port by Alec Kloss <alec@setfilepointer.com>
#
# $FreeBSD$
#

PORTNAME=	openafs
DISTVERSION=	${AFS_DISTVERSION}.${DBVERSION:S/-//g}
PORTREVISION=	1
CATEGORIES=	net kld
MASTER_SITES=	http://dl.central.org/dl/openafs/${AFS_DISTVERSION}/:openafs \
		http://dl.openafs.org/dl/openafs/${AFS_DISTVERSION}/:openafs \
		http://dl.central.org/dl/cellservdb/:gco \
		http://grand.central.org/dl/cellservdb/:gco
DISTFILES=	${PORTNAME}-${AFS_DISTVERSION}-src.tar.bz2:openafs \
		${PORTNAME}-${AFS_DISTVERSION}-doc.tar.bz2:openafs \
		CellServDB.${DBVERSION}:gco
EXTRACT_ONLY=	${PORTNAME}-${AFS_DISTVERSION}-src.tar.bz2 \
		${PORTNAME}-${AFS_DISTVERSION}-doc.tar.bz2

MAINTAINER=	kaduk@mit.edu
COMMENT=	AFS implementation from openafs.org

LICENSE=	IPLv1
LICENSE_NAME=	IBM Public License Version 1.0
LICENSE_FILE=	${WRKSRC}/doc/LICENSE
LICENSE_PERMS=	auto-accept

AFS_DISTVERSION=	1.6.0
DBVERSION=	2011-08-14

OPTIONS=	FUSE "Build afsd.fuse (enable fuse support)" off

USE_LDCONFIG=	yes
PATCH_STRIP=	-p1
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_RC_SUBR=	afsd afsserver
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	i386 amd64

AFSMNTDIR?=	/afs
AFSSTATEDIR?=	/var/${PORTNAME}
AFSCACHEDIR?=	${AFSSTATEDIR}/cache
PLIST_SUB+=	AFSMNTDIR=${AFSMNTDIR:C,^/,,} \
		AFSSTATEDIR=${AFSSTATEDIR:C,^/,,} \
		AFSCACHEDIR=${AFSCACHEDIR:C,^/,,}

.include <bsd.port.pre.mk>

KERNCONF?=	GENERIC
KERNCONFDIR?=	${SRC_BASE}/sys/${ARCH}/conf
KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}

# Use the first component of ${KERNCONF}.
.for K in ${KERNCONF}
_KERNCONF?=$K
.endfor

.if !exists(${KERNCONFDIR}/${_KERNCONF})
IGNORE=	requires kernel configuration file ${_KERNCONF} to build
.endif

.if ${OSVERSION} < 800000
IGNORE=	supports FreeBSD 8.0 and later
.endif

CONFIGURE_ARGS=	--prefix=${PREFIX} \
	--localstatedir=/var \
	--mandir=${MANPREFIX}/man \
	--with-bsd-kernel-headers=${SRC_BASE}/sys \
	--with-bsd-kernel-build=${WRKDIR}/conf \
	--enable-debug \
	--enable-debug-kernel \
	--enable-debug-lwp \
	--includedir=${PREFIX}/include/openafs \
	${CONFIGURE_TARGET}

.if !defined(WITH_FUSE)
CONFIGURE_ARGS+=	--disable-fuse-client
PLIST_SUB+=	FUSE="@comment "
.else
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
PLIST_SUB+=	FUSE=""
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${AFS_DISTVERSION}

CONFLICTS=	coda-server-6.[0-9]* heimdal-[0-9]*

.include "Makefile.man"

# Do not show users the reminder about cleandepend and depend
post-extract:
	${MKDIR} ${WRKDIR}/conf
	cd ${KERNCONFDIR} && /usr/sbin/config -d ${WRKDIR}/conf ${_KERNCONF} >/dev/null

create-sample-files:
	@${ECHO_CMD} openafs.org > ${WRKDIR}/ThisCell
	@${ECHO_CMD} "${AFSMNTDIR}:${AFSCACHEDIR}:150000" > ${WRKDIR}/cacheinfo
	@${INSTALL_DATA} ${DISTDIR}/CellServDB.${DBVERSION} ${WRKDIR}/CellServDB

post-install: create-sample-files
	@${MKDIR} ${PREFIX}/etc/openafs
.for F in CellServDB ThisCell cacheinfo
	@${INSTALL_DATA} ${WRKDIR}/${F} ${PREFIX}/etc/openafs/${F}.sample
	@if [ ! -e ${PREFIX}/etc/openafs/${F} ]; then \
		${INSTALL_DATA} ${WRKDIR}/${F} ${PREFIX}/etc/openafs/${F}; \
	fi
.endfor
	${INSTALL_KLD} ${PREFIX}/lib/openafs/libafs.ko ${KMODDIR}/
	@${RM} ${PREFIX}/lib/openafs/libafs.ko
	@${RMDIR} ${PREFIX}/lib/openafs
	${MKDIR} ${AFSMNTDIR} ${AFSSTATEDIR} ${AFSCACHEDIR}
	/usr/sbin/kldxref ${KMODDIR}

.include <bsd.port.post.mk>
