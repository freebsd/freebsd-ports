# Created by: vanilla
# $FreeBSD$

PORTNAME=	rump
PORTVERSION=	20170822
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Virtualized NetBSD kernel components in userspace

LICENSE=	BSD2CLAUSE

NOT_FOR_ARCHS=	aarch64 armv6 mips mips64 powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to FreeBSD on this architecture

USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_PROJECT=	buildrump.sh
GH_TAGNAME=	b914579
GH_TUPLE=	rumpkernel:src-netbsd:82f3a69:netbsd/src
USE_LDCONFIG=	yes

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} AR=${AR} NM=${NM} OBJCOPY=${OBJCOPY} ./buildrump.sh -r fullbuild

do-install:
	cd ${WRKSRC}/rump; ${PAX} -wr lib include ${STAGEDIR}${PREFIX}/

.include <bsd.port.mk>
