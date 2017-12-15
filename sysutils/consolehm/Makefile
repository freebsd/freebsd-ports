# Created by: Mike Muir <mmuir@es.co.nz>
# $FreeBSD$

PORTNAME=	consolehm
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based hardware monitor for FreeBSD

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86-only assembly from machine/cpufunc.h

USES=		uidfix
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/consolehm/consolehm
MAKE_ARGS+=	-e

PLIST_FILES=	bin/chm man/man8/chm.8.gz

.include <bsd.port.mk>
