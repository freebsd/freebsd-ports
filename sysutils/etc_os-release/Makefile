# $FreeBSD$

PORTNAME=	etc_os-release
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	sysutils kde gnome
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Operating system identification file

NO_BUILD=	yes

PLIST_FILES=	etc/os-release

VERSION!=	freebsd-version -u
VERSION_ID=	${VERSION:C/^([0-9\.]+).*/\1/}

CONTENTS=	'NAME=FreeBSD\0'$\
		'VERSION=${VERSION}\0'$\
		'VERSION_ID=${VERSION_ID}\0'$\
		'ID=freebsd\0'$\
		'ANSI_COLOR="0;31"\0'$\
		'PRETTY_NAME="FreeBSD ${VERSION}"\0'$\
		'CPE_NAME=cpe:/o:freebsd:freebsd:${VERSION_ID}\0'$\
		'HOME_URL=https://freebsd.org/\0'$\
		'BUG_REPORT_URL=https://bugs.freebsd.org'

.include <bsd.port.pre.mk>
# FreeBSD base gained /etc/os-release in r354922, which
# corresponds to __FreeBSD_version 1300060
.if ${OSVERSION} >= 1300060
IGNORE=		/etc/os-release is present in base
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${ECHO} -e ${CONTENTS} | ${XARGS} -0 -n 1 >> ${STAGEDIR}${PREFIX}/${PLIST_FILES}

.include <bsd.port.post.mk>
