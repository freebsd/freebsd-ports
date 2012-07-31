# Ports collection makefile for:  tomsfastmath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

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
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	include/tfm.h lib/libtfm.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.elif ${ARCH} == "powerpc"
BROKEN=		Causes gcc coredump on powerpc
.endif

.include <bsd.port.post.mk>
