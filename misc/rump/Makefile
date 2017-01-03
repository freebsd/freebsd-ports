# Created by: vanilla
# $FreeBSD$

PORTNAME=	rump
PORTVERSION=	20131213
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/stacktic/
DISTNAME=	buildrump-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Virtualized NetBSD kernel components in userspace

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

NOT_FOR_ARCHS=	armv6 mips mips64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to FreeBSD on this architecture

USE_LDCONFIG=	yes
USE_GCC=	any

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} AR=${AR} NM=${NM} OBJCOPY=${OBJCOPY} ./buildrump.sh -r fullbuild

do-install:
	cd ${WRKSRC}/rump; ${PAX} -wr lib include ${STAGEDIR}${PREFIX}/

.include <bsd.port.post.mk>
