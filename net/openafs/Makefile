# New ports collection makefile for:    openafs
# Date created:                         2010-11-06
# Whom:                                 Ben Kaduk <kaduk@mit.edu>
# Based on:                             port by Alec Kloss <alec@setfilepointer.com>
#
# $FreeBSD$
#

PORTNAME=	openafs
DISTVERSION=	1.6.0pre3
CATEGORIES=	net kld
MASTER_SITES=	http://dl.central.org/dl/openafs/candidate/${DISTVERSION}/:openafs \
		http://dl.openafs.org/dl/openafs/candidate/${DISTVERSION}/:openafs \
		http://dl.central.org/dl/cellservdb/:gco \
		http://grand.central.org/dl/cellservdb/:gco
DISTFILES=	${PORTNAME}-${DISTVERSION}-src.tar.bz2:openafs \
		${PORTNAME}-${DISTVERSION}-doc.tar.bz2:openafs \
		CellServDB:gco
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-src.tar.bz2 \
		${PORTNAME}-${DISTVERSION}-doc.tar.bz2

MAINTAINER=	kaduk@mit.edu
COMMENT=	AFS implementation from openafs.org

OPTIONS=	FUSE "Build afsd.fuse (enable fuse support)" off

USE_LDCONFIG=	yes
PATCH_STRIP=	-p1

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_RC_SUBR=	afsd afsserver

ONLY_FOR_ARCHS=	i386 amd64

KERNELDIR=	/usr/obj/usr/src/sys/GENERIC
KMODDIR=	/boot/modules

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=	supports FreeBSD 8.0 and later
.endif

.if !exists(${KERNELDIR}/opt_global.h)
IGNORE= OpenAFS requires opt_global.h from kernel build tree
.endif

CONFIGURE_ARGS=	--prefix=${PREFIX} \
	--localstatedir=/var \
	--mandir=${PREFIX}/man \
	--with-bsd-kernel-build=${KERNELDIR} \
	--enable-debug \
	--enable-debug-kernel \
	--enable-debug-lwp \
	--includedir=${LOCALBASE}/include/openafs \
		${CONFIGURE_TARGET}
#       --with-krb5 KRB5CFLAGS=-I/usr/include \
#       KRB5LIBS='-lkrb5 -lcom_err -lcrypto -lcrypt -lasn1 -lhx509 -lroken' \

.if !defined(WITH_FUSE)
CONFIGURE_ARGS+=	--disable-fuse-client
PLIST_SUB+=	FUSE="@comment "
.else
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
PLIST_SUB+=	FUSE=""
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CONFLICTS=	heimdal-[0-9]*

.include "Makefile.man"

post-install:
	@${MKDIR} ${PREFIX}/etc/openafs
	@${CP} ${DISTDIR}/CellServDB ${PREFIX}/etc/openafs/CellServDB.sample
	@if [ ! -e ${PREFIX}/etc/openafs/CellServDB ] ; then \
		${CP} -p ${PREFIX}/etc/openafs/CellServDB.sample ${PREFIX}/etc/openafs/CellServDB ; \
	fi
	@${ECHO_CMD} openafs.org > ${PREFIX}/etc/openafs/ThisCell.sample
	@if [ ! -e ${PREFIX}/etc/openafs/ThisCell ] ; then \
		${CP} -p ${PREFIX}/etc/openafs/ThisCell.sample ${PREFIX}/etc/openafs/ThisCell ; \
	fi
	@${ECHO_CMD} '/afs:/usr/vice/cache:150000' > ${PREFIX}/etc/openafs/cacheinfo.sample
	@if [ ! -e ${PREFIX}/etc/openafs/cacheinfo ] ; then \
		${CP} -p ${PREFIX}/etc/openafs/cacheinfo.sample ${PREFIX}/etc/openafs/cacheinfo; \
	fi
	${MV} ${PREFIX}/lib/openafs/libafs.ko ${KMODDIR}/
	@${RMDIR} ${PREFIX}/lib/openafs
	kldxref ${KMODDIR}

pre-deinstall:
	@if cmp -s ${PREFIX}/etc/openafs/CellServDB ${PREFIX}/etc/openafs/CellServDB.sample; then \
		${RM} ${PREFIX}/etc/openafs/CellServDB; fi
	@if cmp -s ${PREFIX}/etc/openafs/ThisCell ${PREFIX}/etc/openafs/ThisCell.sample; then \
		${RM} ${PREFIX}/etc/openafs/ThisCell; fi
	@if cmp -s ${PREFIX}/etc/openafs/cacheinfo ${PREFIX}/etc/openafs/cacheinfo.sample; then \
		${RM} ${PREFIX}/etc/openafs/cacheinfo; fi

.include <bsd.port.post.mk>
