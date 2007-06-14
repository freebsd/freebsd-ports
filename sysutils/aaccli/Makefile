# New ports collection makefile for:	aaccli
# Date created:				7 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		aaccli
PORTVERSION=		1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://download.adaptec.com/raid/ccu/freebsd/
DISTNAME=		5400s_fbsd_cli_v10

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Adaptec SCSI RAID administration tool

USE_ZIP=		yes

RESTRICTED=		May not be redistributed in binary form
NO_CDROM=		yes

IA32_BINARY_PORT=	yes
PLIST=			${MASTERDIR}/pkg-plist.i386
MD5_FILE=		${MASTERDIR}/distinfo.i386

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
IGNORE_POST_INSTALL=	I
.endif

do-install:
	${PKG_ADD} -R${IGNORE_POST_INSTALL} ${WRKSRC}/${PKGNAME}_${PORTREVISION}.tgz

.include <bsd.port.post.mk>
