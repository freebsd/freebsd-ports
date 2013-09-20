# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	kldpatch
PORTVERSION=	20090116
CATEGORIES=	sysutils
MASTER_SITES=	http://info.iet.unipi.it/~luigi/FreeBSD/
DISTNAME=	${PORTVERSION}-${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to patch modules and kernel

MAN8=		kldpatch.8
PLIST_FILES=	sbin/kldpatch

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
