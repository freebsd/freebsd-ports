# Created by: kbowling

PORTNAME=		inn-current
PORTVERSION=		${SNAPSHOT}
MASTER_SITE_SUBDIR=	inn/snapshots
DISTNAME=		inn-${BRANCH}-${SNAPSHOT}

BRANCH=		2.7
SNAPSHOT=	20211221

CONFLICTS=	inn-2.[0-9]*

DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/../inn/files
PATCHDIR=	${.CURDIR}/../inn/files
PLIST=		${.CURDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${DISTNAME}

CPE_PRODUCT=	inn

.include "${.CURDIR}/../inn/Makefile"

