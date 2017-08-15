# $FreeBSD$

PORTNAME=	openvas9-libraries
PORTVERSION=	9.0.1
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2420/

COMMENT=	OpenVAS 9 libraries

CONFLICTS=	${PORTNAME:S/${OPENVAS_VER}/8/}-*

MASTERDIR=	${.CURDIR}/../../security/openvas8-libraries

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

OPENVAS_VER=    9

.include "${MASTERDIR}/Makefile"
