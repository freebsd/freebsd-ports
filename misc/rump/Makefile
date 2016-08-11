# Created by: vanilla
# $FreeBSD$

PORTNAME=	rump
PORTVERSION=	20131213
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/stacktic/
DISTNAME=	buildrump-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Virtualized NetBSD kernel components in userspace

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

USE_LDCONFIG=	yes
USE_GCC=	any

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000510
IGNORE=		require 10.0-Release or later
.endif

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} AR=${AR} NM=${NM} OBJCOPY=${OBJCOPY} ./buildrump.sh -r fullbuild

do-install:
	cd ${WRKSRC}/rump; ${PAX} -wr lib include ${STAGEDIR}${PREFIX}/

.include <bsd.port.post.mk>
