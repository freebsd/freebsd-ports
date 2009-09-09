# Ports collection makefile for:  libtommath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	libtommath
PORTVERSION=	0.41
CATEGORIES=	math
MASTER_SITES=	http://libtom.org/files/ \
		http://www.atarininja.org/~wxs/distfiles/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular and portable mathematical routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

.include <bsd.port.mk>
