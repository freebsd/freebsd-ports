# Created by: kaz
# $FreeBSD$

PORTNAME=	nsf
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NAKAMURA's Shell Form input

WRKSRC=		${WRKDIR}
MAN1=		nsf.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/nsf
ALL_TARGET=

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/nsf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${PREFIX}/man/man1/
	${GZIP_CMD} ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
