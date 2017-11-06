# $FreeBSD$

PORTNAME=	openvas9-cli
PORTVERSION=	1.4.5
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2397/

COMMENT=	OpenVAS 9 command-line interface and Nagios plugin

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/8/}-*

MASTERDIR=	${.CURDIR}/../../security/openvas8-cli

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

OPENVAS_VER=	9

.include "${MASTERDIR}/Makefile"
