# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdixtract
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markus
DISTNAME=	PDITOOL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts or converts .pdi file sets to .iso

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

PLIST_FILES=	bin/pdixtract

do-build:
	cd ${WRKDIR}; ${CC} ${CFLAGS} pdixtract.c -o pdixtract

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pdixtract ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
