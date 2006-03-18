# Ports collection makefile for:  tomsfastmath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	tomsfastmath
PORTVERSION=	0.08
CATEGORIES=	math
MASTER_SITES=	http://libtomcrypt.com/tfm/files/
DISTNAME=	tfm-${PORTVERSION}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Portable fixed precision math library for fast exponentiations

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

PLIST_FILES=	include/tfm.h lib/libtfm.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|||' ${WRKSRC}/fp_montgomery_reduce.c

.include <bsd.port.post.mk>
