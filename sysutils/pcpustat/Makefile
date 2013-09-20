# Created by: sterling
# $FreeBSD$

PORTNAME=	pcpustat
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://chipstips.com/download/

MAINTAINER=	sterling@camdensoftware.com
COMMENT=	Per-CPU usage statistics

LICENSE=	OWL

MAN1=		pcpustat.1

USE_BZIP2=	yes
PLIST_FILES=	bin/pcpustat

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
