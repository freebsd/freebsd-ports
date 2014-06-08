# $FreeBSD$

PORTNAME=	tomsfastmath
PORTVERSION=	0.12
CATEGORIES=	math
MASTER_SITES=	http://libtom.org/files/
MASTER_SITE_SUBDIR=	miwi
DISTNAME=	tfm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable fixed precision math library for fast exponentiations

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USES=		gmake tar:bzip2
USE_GCC=	any
ALL_TARGET=	default

PLIST_FILES=	include/tfm.h lib/libtfm.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.elif ${ARCH} == "powerpc"
BROKEN=		Causes gcc coredump on powerpc
.endif

.include <bsd.port.post.mk>
