# New ports collection makefile for:	aaccli
# Date created:				7 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		aaccli
PORTVERSION=		1.0
PORTREVISION=		0
CATEGORIES=		sysutils
MASTER_SITES=		http://download.adaptec.com/raid/ccu/freebsd/
DISTNAME=		5400s_fbsd_cli_v10
EXTRACT_SUFX=		.zip

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Adaptec SCSI RAID administration tool

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=		"May not be redistributed in binary form"
NO_CDROM=		yes

ONLY_FOR_ARCHS=		i386
PLIST=			${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

UNZIP=			unzip

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${UNZIP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${PKG_ADD} -R ${WRKSRC}/${PKGNAME}_${PORTREVISION}.tgz

.include <bsd.port.mk>
