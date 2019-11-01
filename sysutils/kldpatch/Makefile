# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	kldpatch
PORTVERSION=	20090116
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/kldpatch/
DISTNAME=	${PORTVERSION}-${PORTNAME}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Utility to patch modules and kernel

USES=		tar:tgz

PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/kldpatch

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
