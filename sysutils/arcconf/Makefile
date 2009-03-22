# New ports collection makefile for:	arcconf
# Date created:				28 October 2007
# Whom:					michael@fuckner.net
#
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	v6_10_18359
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	asm_freebsd${DIST_EXT}_${DISTVERSION}
EXTRACT_SUFX=	.pkg.tbz

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI RAID administration tool

ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	yes

PLIST_FILES=	sbin/arcconf

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
DIST_EXT=	7_x64
.else
DIST_EXT=	7_x86
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opt/StorMan/arcconf  ${PREFIX}/sbin

.include <bsd.port.post.mk>
