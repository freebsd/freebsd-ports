# $FreeBSD$

PORTNAME=	greenbone-security-assistant9
PORTVERSION=	7.0.2
PORTREVISION=	2
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2429/

COMMENT=	OpenVAS 9 web interface

CONFLICTS=	${PORTNAME:S/${OPENVAS_VER}/8/}-*

MASTERDIR=	${.CURDIR}/../../security/greenbone-security-assistant8

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

OPENVAS_VER=    9

.include "${MASTERDIR}/Makefile"
