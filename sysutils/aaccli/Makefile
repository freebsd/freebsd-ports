# New ports collection makefile for:	aaccli
# Date created:				7 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		aaccli
PORTVERSION=		1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://people.freebsd.org/~scottl/aac/
DISTNAME=		${PORTNAME}-${PORTVERSION}_0
EXTRACT_SUFX=		.tgz

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Adaptec SCSI RAID administration tool

RESTRICTED=		"May not be redistributed in binary form"
NO_CDROM=		yes

ONLY_FOR_ARCHS=		i386
PLIST=			${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

NO_BUILD=		yes

do-install:
	${PKG_ADD} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
