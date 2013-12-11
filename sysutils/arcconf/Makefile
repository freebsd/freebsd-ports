# Created by: michael@fuckner.net
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	v7_30_18837
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	asm_freebsd_${DIST_EXT}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI RAID administration tool

ONLY_FOR_ARCHS=	i386 amd64

PERIODICSCRIPT=	410.status-aac-raid

SUB_FILES+=	${PERIODICSCRIPT}

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	May not be redistributed in binary form

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
DIST_OSVER=	8
.elif ${OSVERSION} >= 700000
DIST_OSVER=	7
.endif

.if ${ARCH} == amd64
DIST_EXT=	x64
.else
DIST_EXT=	x86
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_OSVER}/cmdline/arcconf ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
