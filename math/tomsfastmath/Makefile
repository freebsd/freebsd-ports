# Ports collection makefile for:  tomsfastmath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	tomsfastmath
PORTVERSION=	0.09
CATEGORIES=	math
MASTER_SITES=	http://libtomcrypt.com/tfm/files/ \
		http://www.atarininja.org/~wxs/distfiles/
DISTNAME=	tfm-${PORTVERSION}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Portable fixed precision math library for fast exponentiations

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

PLIST_FILES=	include/tfm.h lib/libtfm.a

NOT_FOR_ARCHS=	sparc64

.include <bsd.port.mk>
