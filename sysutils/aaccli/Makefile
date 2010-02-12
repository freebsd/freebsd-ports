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
DEPRECATED=		see sysutils/arcconf instead, no longer maintained by Adaptec
EXPIRATION_DATE=	2010-05-11

IA32_BINARY_PORT=	yes
PLIST=			${MASTERDIR}/pkg-plist.i386
MD5_FILE=		${MASTERDIR}/distinfo.i386

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

do-install:
	${PKG_ADD} -RI ${WRKSRC}/${PKGNAME}_${PORTREVISION}.tgz

.include <bsd.port.mk>
