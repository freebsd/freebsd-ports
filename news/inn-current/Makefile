# Created by: kbowling

PORTNAME=		inn-current
PORTVERSION=		${SNAPSHOT}
MASTER_SITE_SUBDIR=	inn/snapshots
DISTNAME=		inn-${BRANCH}-${SNAPSHOT}

BRANCH=		CURRENT
SNAPSHOT=	20210630

CONFLICTS=	inn-2.[0-9]*

DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/../inn/files
PATCHDIR=	${.CURDIR}/../inn/files
PLIST=		${.CURDIR}/../inn/pkg-plist
WRKSRC=		${WRKDIR}/${DISTNAME}

.include "${.CURDIR}/../inn/Makefile"

