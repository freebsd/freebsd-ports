# ports collection makefile for:	nsf
# Date created:				2000/09/09
# Whom:					kaz
#
# $FreeBSD$
#

PORTNAME=	nsf
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	kaz@kobe1995.net
COMMENT=	NAKAMURA's Shell Form input

WRKSRC=		${WRKDIR}
MAN1=		nsf.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/nsf
ALL_TARGET=

post-install:
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${PREFIX}/man/man1/
	${GZIP_CMD} ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
