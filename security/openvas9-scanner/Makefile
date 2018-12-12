# $FreeBSD$

PORTNAME=	openvas9-scanner
PORTVERSION=	5.1.1
PORTREVISION=	2
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2423/

COMMENT=	OpenVAS 9 scanner

CONFLICTS=	${PORTNAME:S/${OPENVAS_VER}/8/}-*

MASTERDIR=	${.CURDIR}/../../security/openvas8-scanner

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

OPENVAS_VER=	9

.include "${MASTERDIR}/Makefile"
