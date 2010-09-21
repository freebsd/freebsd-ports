# New ports collection makefile for:   pcpustat
# Date created:        13 July 2010
# Whom:                sterling
#
# $FreeBSD$
#

PORTNAME=	pcpustat
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://chipstips.com/download/

MAINTAINER=	sterling@camdensoftware.com
COMMENT=	Per-CPU usage statistics

MAN1=		pcpustat.1

USE_BZIP2=	yes
PLIST_FILES=	bin/pcpustat

LICENSE=	OWL
LICENSE_NAME=	Open Works License
LICENSE_PERMS=	none
LICENSE_FILE=	${FILESDIR}/license.txt
MANUAL_PACKAGE_BUILD=	needs interactive license confirmation

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
