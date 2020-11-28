# Created by: vanilla
# $FreeBSD$

PORTNAME=	rump
PORTVERSION=	20170822
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Virtualized NetBSD kernel components in userspace

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	only supports FreeBSD on this architecture

USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_PROJECT=	buildrump.sh
GH_TAGNAME=	b914579
GH_TUPLE=	rumpkernel:src-netbsd:82f3a69:netbsd/src
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	X8664=""
.else
PLIST_SUB+=	X8664="@comment "
.endif

CFLAGS+=	-Wno-address-of-packed-member

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} AR=${AR} NM=${NM} OBJCOPY=${OBJCOPY} ./buildrump.sh -F CFLAGS="${CFLAGS}" -r fullbuild

do-install:
	cd ${WRKSRC}/rump; ${PAX} -wr lib include ${STAGEDIR}${PREFIX}/

.include <bsd.port.post.mk>
