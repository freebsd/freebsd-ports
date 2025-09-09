PORTNAME=	rump
PORTVERSION=	20170822
PORTREVISION=	4
CATEGORIES=	misc

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Virtualized NetBSD kernel components in userspace
WWW=		https://www.rumpkernel.org

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	only supports FreeBSD on this architecture

USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_PROJECT=	buildrump.sh
GH_TAGNAME=	b914579
GH_TUPLE=	rumpkernel:src-netbsd:82f3a69:netbsd/src
USE_LDCONFIG=	yes
USES=		compiler

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=strict-prototypes -Wno-error=array-parameter -Wno-error=cast-function-type-mismatch
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	X8664=""
.else
PLIST_SUB+=	X8664="@comment "
.endif

CWARNFLAGS+=	-Wno-address-of-packed-member
.if ${COMPILER_TYPE} == clang
CWARNFLAGS+=	-Wno-unused-but-set-variable
.endif

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} AR=${AR} NM=${NM} OBJCOPY=${OBJCOPY} ./buildrump.sh -F CFLAGS="${CFLAGS}" -F CWARNFLAGS="${CWARNFLAGS}" -r fullbuild

do-install:
	cd ${WRKSRC}/rump; ${PAX} -wr lib include ${STAGEDIR}${PREFIX}/

.include <bsd.port.post.mk>
